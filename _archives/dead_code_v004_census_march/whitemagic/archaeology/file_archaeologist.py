from __future__ import annotations
from whitemagic.utils.core import parse_datetime

import asyncio
import json
import hashlib
from dataclasses import dataclass, field, asdict
from datetime import datetime
from pathlib import Path
from typing import Dict, List, Optional, Any
from threading import Lock
import fnmatch

from whitemagic.config.paths import WM_ROOT

# Singleton instance
_archaeologist_instance: Optional['FileArchaeologist'] = None
_archaeologist_lock = Lock()


@dataclass
class ReadEntry:
    """Record of a file we've read."""
    path: str
    first_read: str
    last_read: str
    times_read: int = 1
    last_write: Optional[str] = None
    times_written: int = 0
    content_hash: Optional[str] = None
    contexts: List[str] = field(default_factory=list)
    notes: List[str] = field(default_factory=list)
    write_notes: List[str] = field(default_factory=list)
    file_type: str = "unknown"
    line_count: Optional[int] = None
    size_bytes: Optional[int] = None
    key_insights: List[str] = field(default_factory=list)
    related_memories: List[str] = field(default_factory=list)
    
    def to_dict(self) -> Dict[str, Any]:
        return asdict(self)
    
    @classmethod
    def from_dict(cls, data: Dict[str, Any]) -> 'ReadEntry':
        return cls(**data)
    
    def age_hours(self) -> float:
        """Hours since last read."""
        last = parse_datetime(self.last_read)
        return (datetime.utcnow() - last).total_seconds() / 3600


class FileArchaeologist:
    """
    Track everything we've ever read, with memory integration.
    
    This is the enhanced version of SeenRegistry that:
    - Connects to the memory system for relevance
    - Discovers unread files
    - Tracks reading patterns
    - Exposes MCP tools
    """
    
    def __init__(self, storage_path: Optional[Path] = None) -> None:
        self.storage_path = storage_path or WM_ROOT / "archaeology" / "readings.json"
        self.storage_path.parent.mkdir(parents=True, exist_ok=True)
        self._entries: Dict[str, ReadEntry] = {}
        self._load()
    
    def _load(self) -> None:
        """Load registry from disk."""
        if self.storage_path.exists():
            try:
                data = json.loads(self.storage_path.read_text())
                self._entries = {
                    k: ReadEntry.from_dict(v) 
                    for k, v in data.get("entries", {}).items()
                }
            except Exception:
                self._entries = {}
    
    def _save(self) -> None:
        """Save registry to disk."""
        data = {
            "version": "1.0",
            "updated": datetime.utcnow().isoformat(),
            "total_entries": len(self._entries),
            "entries": {k: v.to_dict() for k, v in self._entries.items()}
        }
        self.storage_path.write_text(json.dumps(data, indent=2))
    
    def _hash_content(self, path: str) -> Optional[str]:
        """Generate hash of file content."""
        try:
            content = Path(path).read_bytes()
            return hashlib.sha256(content).hexdigest()[:16]
        except Exception:
            return None
    
    def _detect_type(self, path: str) -> str:
        """Detect file type from extension."""
        ext = Path(path).suffix.lower()
        type_map = {
            '.md': 'markdown', '.py': 'python', '.js': 'javascript',
            '.ts': 'typescript', '.json': 'json', '.yaml': 'yaml',
            '.yml': 'yaml', '.html': 'html', '.css': 'css',
            '.rs': 'rust', '.toml': 'toml', '.txt': 'text',
            '.pb': 'protobuf', '.proto': 'protobuf',
        }
        return type_map.get(ext, 'unknown')
    
    def _count_lines(self, path: str) -> Optional[int]:
        """Count lines in text file."""
        try:
            return len(Path(path).read_text().splitlines())
        except Exception:
            return None
    
    def _get_size(self, path: str) -> Optional[int]:
        """Get file size in bytes."""
        try:
            return Path(path).stat().st_size
        except Exception:
            return None
    
    # =========================================================================
    # Core Reading Tracking
    # =========================================================================
    
    def mark_read(
        self, 
        path: str, 
        context: Optional[str] = None,
        note: Optional[str] = None,
        insight: Optional[str] = None
    ) -> ReadEntry:
        """
        Mark a file as read.
        
        Args:
            path: Path to the file
            context: Why we're reading it (e.g., "Phase 1 scan", "Bug investigation")
            note: Any notes about what we found
            insight: Key insight extracted from the file
            
        Returns:
            The ReadEntry record
        """
        now = datetime.utcnow().isoformat()
        abs_path = str(Path(path).resolve())
        
        if abs_path in self._entries:
            entry = self._entries[abs_path]
            entry.last_read = now
            entry.times_read += 1
            entry.content_hash = self._hash_content(abs_path)
            if context and context not in entry.contexts:
                entry.contexts.append(context)
            if note:
                entry.notes.append(f"[{now[:10]}] {note}")
            if insight and insight not in entry.key_insights:
                entry.key_insights.append(insight)
        else:
            entry = ReadEntry(
                path=abs_path,
                first_read=now,
                last_read=now,
                content_hash=self._hash_content(abs_path),
                contexts=[context] if context else [],
                notes=[f"[{now[:10]}] {note}"] if note else [],
                file_type=self._detect_type(abs_path),
                line_count=self._count_lines(abs_path),
                size_bytes=self._get_size(abs_path),
                key_insights=[insight] if insight else [],
            )
            self._entries[abs_path] = entry
        
        self._save()
        return entry

    def mark_written(
        self,
        path: str,
        context: Optional[str] = None,
        note: Optional[str] = None,
    ) -> ReadEntry:
        """
        Mark a file as written.

        Args:
            path: Path to the file
            context: Why we wrote it
            note: Any notes about the write

        Returns:
            The ReadEntry record
        """
        now = datetime.utcnow().isoformat()
        abs_path = str(Path(path).resolve())

        if abs_path in self._entries:
            entry = self._entries[abs_path]
            entry.last_write = now
            entry.times_written += 1
            entry.content_hash = self._hash_content(abs_path)
            entry.line_count = self._count_lines(abs_path)
            entry.size_bytes = self._get_size(abs_path)
            if context and context not in entry.contexts:
                entry.contexts.append(context)
            if note:
                entry.write_notes.append(f"[{now[:10]}] {note}")
        else:
            entry = ReadEntry(
                path=abs_path,
                first_read=now,
                last_read=now,
                last_write=now,
                times_written=1,
                content_hash=self._hash_content(abs_path),
                contexts=[context] if context else [],
                write_notes=[f"[{now[:10]}] {note}"] if note else [],
                file_type=self._detect_type(abs_path),
                line_count=self._count_lines(abs_path),
                size_bytes=self._get_size(abs_path),
            )
            self._entries[abs_path] = entry

        self._save()
        return entry
    
    def have_read(self, path: str) -> bool:
        """Check if we've read a file before."""
        abs_path = str(Path(path).resolve())
        return abs_path in self._entries
    
    def when_read(self, path: str) -> Optional[str]:
        """Get when we last read a file."""
        abs_path = str(Path(path).resolve())
        entry = self._entries.get(abs_path)
        return entry.last_read if entry else None
    
    def get_entry(self, path: str) -> Optional[ReadEntry]:
        """Get full entry for a file."""
        abs_path = str(Path(path).resolve())
        return self._entries.get(abs_path)
    
    def has_changed(self, path: str) -> bool:
        """Check if file content has changed since we last read it."""
        abs_path = str(Path(path).resolve())
        entry = self._entries.get(abs_path)
        if not entry or not entry.content_hash:
            return True
        current_hash = self._hash_content(abs_path)
        return current_hash != entry.content_hash
    
    # =========================================================================
    # Discovery & Analysis
    # =========================================================================
    
    def get_recent_reads(self, limit: int = 50) -> List[ReadEntry]:
        """Get most recently read files."""
        sorted_entries = sorted(
            self._entries.values(),
            key=lambda e: e.last_read,
            reverse=True
        )
        return sorted_entries[:limit]
    
    def get_by_type(self, file_type: str) -> List[ReadEntry]:
        """Get all entries of a specific type."""
        return [e for e in self._entries.values() if e.file_type == file_type]
    
    def get_by_context(self, context: str) -> List[ReadEntry]:
        """Get all entries with a specific context."""
        return [e for e in self._entries.values() if context in e.contexts]
    
    def find_unread(
        self, 
        directory: str, 
        patterns: Optional[List[str]] = None,
        exclude_patterns: Optional[List[str]] = None
    ) -> List[str]:
        """
        Find files in a directory that we haven't read yet.
        
        Args:
            directory: Directory to scan
            patterns: Glob patterns to include (e.g., ["*.md", "*.py"])
            exclude_patterns: Patterns to exclude (e.g., ["node_modules/*"])
            
        Returns:
            List of unread file paths
        """
        patterns = patterns or ["*"]
        exclude_patterns = exclude_patterns or [
            "node_modules/*", "__pycache__/*", ".git/*", 
            "*.pyc", "*.egg-info/*", "dist/*", "build/*"
        ]
        
        dir_path = Path(directory)
        if not dir_path.exists():
            return []
        
        unread = []
        for pattern in patterns:
            for file_path in dir_path.rglob(pattern):
                if not file_path.is_file():
                    continue
                
                rel_path = str(file_path.relative_to(dir_path))
                
                # Check exclusions
                excluded = False
                for exc in exclude_patterns:
                    if fnmatch.fnmatch(rel_path, exc):
                        excluded = True
                        break
                
                if excluded:
                    continue
                
                # Check if we've read it
                abs_path = str(file_path.resolve())
                if abs_path not in self._entries:
                    unread.append(abs_path)
        
        return unread
    
    def find_changed(self, directory: Optional[str] = None) -> List[ReadEntry]:
        """Find files we've read that have changed since."""
        changed = []
        entries = self._entries.values()
        
        if directory:
            dir_path = str(Path(directory).resolve())
            entries = [e for e in entries if e.path.startswith(dir_path)]
        
        for entry in entries:
            if Path(entry.path).exists() and self.has_changed(entry.path):
                changed.append(entry)
        
        return changed
    
    def find_stale(self, hours: int = 168) -> List[ReadEntry]:
        """Find files we haven't re-read in a while (default: 1 week)."""
        stale = []
        for entry in self._entries.values():
            if entry.age_hours() > hours:
                stale.append(entry)
        return sorted(stale, key=lambda e: e.last_read)
    
    # =========================================================================
    # Memory Integration
    # =========================================================================
    
    def link_memory(self, path: str, memory_id: str) -> None:
        """Link a memory to a file."""
        abs_path = str(Path(path).resolve())
        entry = self._entries.get(abs_path)
        if entry and memory_id not in entry.related_memories:
            entry.related_memories.append(memory_id)
            self._save()
    
    def get_relevant_memories(self, path: str) -> List[str]:
        """Get memory IDs relevant to a file."""
        abs_path = str(Path(path).resolve())
        entry = self._entries.get(abs_path)
        return entry.related_memories if entry else []
    
    def add_insight(self, path: str, insight: str) -> None:
        """Add a key insight extracted from a file."""
        abs_path = str(Path(path).resolve())
        entry = self._entries.get(abs_path)
        if entry and insight not in entry.key_insights:
            entry.key_insights.append(insight)
            self._save()
    
    # =========================================================================
    # Statistics & Reports
    # =========================================================================
    
    def _get_disk_usage(self, directory: Path) -> Dict[str, Any]:
        """Calculate disk usage and find large artifacts."""
        import os
        total_size = 0
        file_count = 0
        large_files = []
        artifact_types = {
            'models': ['.gguf', '.safetensors', '.bin', '.pt', '.pth'],
            'archives': ['.tar.gz', '.zip', '.rar', '.7z'],
            'builds': ['.so', '.o', '.a', '.dll', '.exe'],
            'data': ['.db', '.sqlite', '.sqlite3', '.db-wal']
        }
        artifacts_found = {k: 0 for k in artifact_types}
        
        exclude_dirs = {
            'node_modules', '_detached_assets', 'target', 'build', 'dist', 
            '__pycache__', '.git', '.venv', 'venv', 'env', '.pixi', '.next', '.zig-cache',
            'whitemagic-models' # Exclude models dir if it exists
        }
        
        try:
            # Use os.walk for better control over directory exclusion
            for root, dirs, files in os.walk(str(directory)):
                # Prune excluded directories in-place
                dirs[:] = [d for d in dirs if d not in exclude_dirs and not d.startswith('.')]
                
                for file in files:
                    if file.startswith('.'):
                        continue
                        
                    try:
                        p = Path(root) / file
                        size = p.stat().st_size
                        total_size += size
                        file_count += 1
                        
                        # Track large files (>100MB)
                        if size > 100 * 1024 * 1024:
                            large_files.append({
                                'path': str(p),
                                'size_mb': round(size / (1024 * 1024), 2)
                            })
                            
                        # Track artifact types
                        suffix = p.suffix.lower()
                        for cat, exts in artifact_types.items():
                            if suffix in exts:
                                artifacts_found[cat] += 1
                                break
                    except (OSError, PermissionError):
                        continue
        except Exception:
            pass
            
        return {
            'disk_usage_mb': round(total_size / (1024 * 1024), 2),
            'disk_file_count': file_count,
            'large_files': sorted(large_files, key=lambda x: x['size_mb'], reverse=True)[:10],
            'artifacts': artifacts_found
        }

    def stats(self, scan_disk: bool = False) -> Dict[str, Any]:
        """Get reading statistics."""
        by_type: Dict[str, int] = {}
        by_context: Dict[str, int] = {}
        total_reads = 0
        total_writes = 0
        total_lines = 0
        total_bytes = 0
        
        for entry in self._entries.values():
            by_type[entry.file_type] = by_type.get(entry.file_type, 0) + 1
            total_reads += entry.times_read
            total_writes += entry.times_written
            if entry.line_count:
                total_lines += entry.line_count
            if entry.size_bytes:
                total_bytes += entry.size_bytes
            for ctx in entry.contexts:
                by_context[ctx] = by_context.get(ctx, 0) + 1
        
        result = {
            "total_files": len(self._entries),
            "total_reads": total_reads,
            "total_writes": total_writes,
            "total_lines": total_lines,
            "total_bytes": total_bytes,
            "total_mb": round(total_bytes / (1024 * 1024), 2),
            "by_type": by_type,
            "by_context": by_context,
            "storage_path": str(self.storage_path)
        }
        
        if scan_disk:
            # Scan from project root (assumed to be 3 levels up from this file)
            # whitemagic/whitemagic/archaeology/file_archaeologist.py -> whitemagic/whitemagic -> whitemagic -> ROOT
            project_root = Path(__file__).parent.parent.parent.parent
            disk_stats = self._get_disk_usage(project_root)
            result.update(disk_stats)
            
        return result
    
    def reading_report(self) -> str:
        """Generate a human-readable reading report."""
        stats = self.stats()
        lines = [
            "📚 File Archaeology Report",
            "=" * 40,
            f"Total Files Read: {stats['total_files']}",
            f"Total Read Events: {stats['total_reads']}",
            f"Total Write Events: {stats['total_writes']}",
            f"Total Lines: {stats['total_lines']:,}",
            f"Total Size: {stats['total_mb']} MB",
            "",
            "📂 By Type:",
        ]
        
        for ftype, count in sorted(stats['by_type'].items(), key=lambda x: -x[1]):
            lines.append(f"  {ftype}: {count}")
        
        if stats['by_context']:
            lines.append("")
            lines.append("🏷️ By Context:")
            for ctx, count in sorted(stats['by_context'].items(), key=lambda x: -x[1])[:10]:
                lines.append(f"  {ctx}: {count}")
        
        return "\n".join(lines)
    
    def search(self, query: str) -> List[ReadEntry]:
        """Search entries by path, notes, or insights."""
        query_lower = query.lower()
        results = []
        for entry in self._entries.values():
            if query_lower in entry.path.lower():
                results.append(entry)
            elif any(query_lower in note.lower() for note in entry.notes):
                results.append(entry)
            elif any(query_lower in insight.lower() for insight in entry.key_insights):
                results.append(entry)
        return results
    
    def clear(self) -> None:
        """Clear all entries (use with caution!)."""
        self._entries = {}
        self._save()


def get_archaeologist() -> FileArchaeologist:
    """Get singleton FileArchaeologist instance."""
    global _archaeologist_instance
    with _archaeologist_lock:
        if _archaeologist_instance is None:
            _archaeologist_instance = FileArchaeologist()
        return _archaeologist_instance


# =========================================================================
# Convenience Functions
# =========================================================================

def mark_read(path: str, context: Optional[str] = None, note: Optional[str] = None) -> ReadEntry:
    """Mark a file as read."""
    return get_archaeologist().mark_read(path, context, note)

def mark_written(path: str, context: Optional[str] = None, note: Optional[str] = None) -> ReadEntry:
    """Mark a file as written."""
    return get_archaeologist().mark_written(path, context, note)

async def mark_read_async(
    path: str,
    context: Optional[str] = None,
    note: Optional[str] = None,
) -> ReadEntry:
    """Async mark read wrapper."""
    return await asyncio.to_thread(get_archaeologist().mark_read, path, context, note)

async def mark_written_async(
    path: str,
    context: Optional[str] = None,
    note: Optional[str] = None,
) -> ReadEntry:
    """Async mark write wrapper."""
    return await asyncio.to_thread(get_archaeologist().mark_written, path, context, note)

def have_read(path: str) -> bool:
    """Check if we've read a file."""
    return get_archaeologist().have_read(path)

def find_unread(directory: str, patterns: Optional[List[str]] = None) -> List[str]:
    """Find unread files in a directory."""
    return get_archaeologist().find_unread(directory, patterns)

def reading_stats() -> Dict[str, Any]:
    """Get reading statistics."""
    return get_archaeologist().stats()
