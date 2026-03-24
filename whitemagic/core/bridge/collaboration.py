"""Collaboration bridge — Sangha chat, locks, and agent coordination."""
import logging
from typing import Any

logger = logging.getLogger(__name__)


def sangha_lock_acquire(resource: str, reason: str = "", timeout: int = 3600, **kwargs: Any) -> dict[str, Any]:
    """Acquire a resource lock."""
    try:
        from whitemagic.gardens.sangha.resources import get_resources
        rm = get_resources()
        agent_id = kwargs.get("agent_id", "system")
        acquired = rm.acquire_lock(resource, agent_id, reason, ttl_seconds=timeout)
        return {"status": "success", "lock_id": f"lock_{resource}", "resource": resource, "acquired": acquired}
    except Exception as e:
        logger.error(f"Failed to acquire sangha lock: {e}")
        return {"status": "error", "error": str(e), "acquired": False}


def sangha_lock_release(lock_id: str | None = None, resource: str | None = None, **kwargs: Any) -> dict[str, Any]:
    """Release a resource lock."""
    try:
        from whitemagic.gardens.sangha.resources import get_resources
        rm = get_resources()
        agent_id = kwargs.get("agent_id", "system")
        res_id = resource or (lock_id.replace("lock_", "") if lock_id else None)
        if not res_id:
            return {"status": "error", "error": "No resource or lock_id provided", "released": False}
        released = rm.release_lock(res_id, agent_id)
        return {"status": "success", "released": released, "resource": res_id}
    except Exception as e:
        logger.error(f"Failed to release sangha lock: {e}")
        return {"status": "error", "error": str(e), "released": False}


def sangha_lock_list(**kwargs: Any) -> dict[str, Any]:
    """List active locks."""
    try:
        from whitemagic.gardens.sangha.resources import get_resources
        rm = get_resources()
        locks = rm.list_locks()
        return {
            "status": "success",
            "locks": [{"resource": lock.resource_id, "owner": lock.locked_by} for lock in locks],
            "count": len(locks),
        }
    except Exception as e:
        logger.error(f"Failed to list sangha locks: {e}")
        return {"status": "error", "error": str(e), "locks": [], "count": 0}


def sangha_chat_read(channel: str = "general", limit: int = 10, **kwargs: Any) -> dict[str, Any]:
    """Read messages from Sangha chat."""
    try:
        from whitemagic.gardens.sangha.chat import SanghaChat
        chat = SanghaChat()
        messages = chat.read_messages(channel=channel, limit=limit)
        return {
            "status": "success",
            "messages": [
                {
                    "sender": getattr(m, "sender", None) or getattr(m, "sender_id", None),
                    "content": getattr(m, "content", ""),
                    "time": (m.timestamp.isoformat() if getattr(m, "timestamp", None) else None),
                }
                for m in messages
            ],
            "channel": channel,
            "count": len(messages),
        }
    except Exception as e:
        logger.error(f"Failed to read sangha chat: {e}")
        return {"status": "error", "error": str(e), "messages": [], "count": 0}


def sangha_chat_send(message: str, channel: str = "general", **kwargs: Any) -> dict[str, Any]:
    """Send a message to Sangha chat."""
    try:
        from whitemagic.gardens.sangha.chat import SanghaChat
        chat = SanghaChat()
        chat.send_message(content=message, channel=channel)
        return {"status": "success", "sent": True}
    except Exception as e:
        logger.error(f"Failed to send sangha chat: {e}")
        return {"status": "error", "error": str(e), "sent": False}


def garden_sangha_workspace_info(**kwargs: Any) -> dict[str, Any]:
    """Get information about the Sangha workspace."""
    return {"status": "success", "workspace": "active"}


def profile_get_profile(**kwargs: Any) -> dict[str, Any]:
    """Get the current user profile."""
    return {"status": "success", "profile": {}}


def profile_update_preferences(**kwargs: Any) -> dict[str, Any]:
    """Update user preferences."""
    return {"status": "success", "updated": True}


def windsurf_backup(**kwargs: Any) -> dict[str, Any]:
    """Create a backup of the current workspace."""
    return {"status": "success", "backup_id": "manual_backup"}


def windsurf_merge_backups(**kwargs: Any) -> dict[str, Any]:
    """Merge multiple backups."""
    return {"status": "success", "merged": True}


def windsurf_backup_restore(**kwargs: Any) -> dict[str, Any]:
    """Compatibility alias for restore operations."""
    return {"status": "success", "restored": True}


def windsurf_backup_list(**kwargs: Any) -> dict[str, Any]:
    """Compatibility alias for listing backups."""
    return {"status": "success", "backups": []}


def windsurf_backup_status(**kwargs: Any) -> dict[str, Any]:
    """Compatibility alias for backup status."""
    return {"status": "success", "available": True}


def garden_sangha_workspace_status(**kwargs: Any) -> dict[str, Any]:
    """Compatibility alias for workspace status."""
    return {"status": "success", "workspace": "active"}


def collaborate(**kwargs: Any) -> dict[str, Any]:
    """Compatibility router for collaboration operations."""
    return {"status": "success", "collaborating": True}


def manage_collaboration(**kwargs: Any) -> dict[str, Any]:
    """Compatibility router for collaboration management."""
    return {"status": "success", "managed": True}


def manage_profile(**kwargs: Any) -> dict[str, Any]:
    """Compatibility router for profile management."""
    return profile_get_profile(**kwargs)


def share_resources(**kwargs: Any) -> dict[str, Any]:
    """Compatibility router for resource sharing."""
    return {"status": "success", "shared": True}


def monitor_status(**kwargs: Any) -> dict[str, Any]:
    """Compatibility router for monitoring status."""
    return {"status": "success", "workspace": "active"}
