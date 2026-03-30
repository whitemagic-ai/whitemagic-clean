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
        from whitemagic.gardens.sangha.chat import get_chat
        chat = get_chat()
        messages = chat.read_messages(channel=channel, limit=limit)
        return {
            "status": "success",
            "messages": [
                {
                    "sender": getattr(m, "sender_id", None),
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


def sangha_chat_send(content: str, channel: str = "general", sender_id: str = "system", **kwargs: Any) -> dict[str, Any]:
    """Send a message to Sangha chat."""
    try:
        from whitemagic.gardens.sangha.chat import get_chat
        chat = get_chat()
        
        tags = kwargs.get("tags")
        priority = kwargs.get("priority", "normal")
        reply_to = kwargs.get("reply_to")
        
        msg = chat.send_message(
            sender_id=sender_id,
            content=content,
            channel=channel,
            tags=tags,
            priority=priority,
            reply_to=reply_to
        )
        
        # --- Sangha Galaxy Integration ---
        # 1. Encode message into 5D coordinates
        try:
            from whitemagic.core.intelligence.hologram.encoder import CoordinateEncoder
            encoder = CoordinateEncoder()
            coords = encoder.encode(msg.to_dict())
            
            # 2. Broadcast high-speed signal via PolyglotRouter
            from whitemagic.optimization.polyglot_router import get_router
            router = get_router()
            router.send_sangha_signal(
                id=msg.id,
                sender_id=sender_id,
                content=content,
                channel=channel,
                coords=coords.to_vector()
            )
        except Exception as e:
            logger.warning(f"Failed to broadcast 5D sangha signal: {e}")
        # ---------------------------------
        
        return {
            "status": "success",
            "message_id": msg.id,
            "channel": channel,
            "timestamp": msg.timestamp.isoformat()
        }
    except Exception as e:
        logger.error(f"Failed to send sangha chat message: {e}")
        return {"status": "error", "error": str(e)}
