"""WhiteMagic Utilities Package.
"""

from .core import (
    create_frontmatter,
    create_preview,
    format_size,
    normalize_tags,
    now_iso,
    parse_datetime,
    parse_frontmatter,
    serialize_frontmatter,
    slugify,
    split_frontmatter,
    summarize_text,
    truncate_text,
)
from .fileio import atomic_write, file_lock
# import_optimizer archived as dead code (0 importers)
from .observability import get_tracker, track_metric
from .text_cleaning import clean_markdown

__all__ = [
    "atomic_write",
    "clean_markdown",
    "create_frontmatter",
    "create_preview",
    "file_lock",
    "format_size",
    "get_tracker",
    "normalize_tags",
    "now_iso",
    "parse_datetime",
    "parse_frontmatter",
    "serialize_frontmatter",
    "slugify",
    "split_frontmatter",
    "summarize_text",
    "track_metric",
    "truncate_text",
]
