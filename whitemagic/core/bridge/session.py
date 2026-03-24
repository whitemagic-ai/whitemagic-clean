from __future__ import annotations

from typing import Any

from whitemagic.sessions.manager import Session, SessionManager, SessionStatus

_SESSION_MANAGER = SessionManager()


def _serialize_session(session: Session | None) -> dict[str, Any]:
    if session is None:
        return {}
    return session.to_dict()


def session_init(name: str = "session", goals: list[str] | None = None, tags: list[str] | None = None, **kwargs: Any) -> dict[str, Any]:
    """Create a new work session."""
    session_name = kwargs.get("session_name") or kwargs.get("title") or name
    session = _SESSION_MANAGER.create_session(name=session_name, goals=goals, tags=tags)
    return {"status": "success", "session": session.to_dict()}


def session_list(limit: int = 10, status: str | None = None, **kwargs: Any) -> dict[str, Any]:
    """List recent sessions."""
    status_enum = None
    if status:
        try:
            status_enum = SessionStatus(status)
        except ValueError:
            return {"status": "error", "error": f"Unknown session status: {status}"}

    sessions = _SESSION_MANAGER.list_sessions(status=status_enum, limit=limit)
    return {"status": "success", "sessions": [session.to_dict() for session in sessions], "count": len(sessions)}


def session_get_context(session_id: str | None = None, **kwargs: Any) -> dict[str, Any]:
    """Get the context for a session or the active session."""
    session = _SESSION_MANAGER.get_session(session_id) if session_id else _SESSION_MANAGER.get_active_session()
    if not session:
        return {"status": "error", "error": "No session found", "context": {}}
    return {"status": "success", "session": _serialize_session(session), "context": session.context}


def session_checkpoint(session_id: str | None = None, context: dict[str, Any] | None = None, metrics: dict[str, Any] | None = None, **kwargs: Any) -> dict[str, Any]:
    """Persist a session checkpoint."""
    session = _SESSION_MANAGER.get_session(session_id) if session_id else _SESSION_MANAGER.get_active_session()
    if not session:
        return {"status": "error", "error": "No session found to checkpoint"}

    updates: dict[str, Any] = {}
    if context is not None:
        updates["context"] = context
    if metrics is not None:
        updates["metrics"] = metrics

    updated = _SESSION_MANAGER.update_session(session.id, **updates)
    if not updated:
        return {"status": "error", "error": "Failed to update session checkpoint"}

    return {"status": "success", "session": updated.to_dict(), "checkpointed": True}


def session_handoff(session_id: str | None = None, target_session_id: str | None = None, handoff_context: dict[str, Any] | None = None, **kwargs: Any) -> dict[str, Any]:
    """Create a session handoff payload."""
    session = _SESSION_MANAGER.get_session(session_id) if session_id else _SESSION_MANAGER.get_active_session()
    if not session:
        return {"status": "error", "error": "No session found to hand off"}

    payload = {
        "from_session": session.id,
        "to_session": target_session_id,
        "context": handoff_context or session.context,
        "goals": session.goals,
        "tags": session.tags,
    }
    return {"status": "success", "handoff": payload}


def session_create_handoff(**kwargs: Any) -> dict[str, Any]:
    """Legacy alias for session_handoff."""
    return session_handoff(**kwargs)


__all__ = [
    "session_checkpoint",
    "session_create_handoff",
    "session_get_context",
    "session_handoff",
    "session_init",
    "session_list",
]
