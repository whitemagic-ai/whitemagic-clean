"""WebSocket routes for real-time AI agent communication."""

import json
from typing import Dict, Set
from datetime import datetime

from fastapi import APIRouter, WebSocket, WebSocketDisconnect

from app.database import AsyncSessionLocal
from models import Session

router = APIRouter()

# Active WebSocket connections
class ConnectionManager:
    """Manages WebSocket connections for real-time updates."""
    
    def __init__(self):
        # session_id -> Set[WebSocket]
        self.active_connections: Dict[str, Set[WebSocket]] = {}
        # agent_id -> Set[WebSocket] (for agent-wide broadcasts)
        self.agent_connections: Dict[str, Set[WebSocket]] = {}
    
    async def connect(self, websocket: WebSocket, session_id: str, agent_id: str):
        """Accept a new WebSocket connection."""
        await websocket.accept()
        
        if session_id not in self.active_connections:
            self.active_connections[session_id] = set()
        self.active_connections[session_id].add(websocket)
        
        if agent_id not in self.agent_connections:
            self.agent_connections[agent_id] = set()
        self.agent_connections[agent_id].add(websocket)
        
        # Update session with connection info
        async with AsyncSessionLocal() as db:
            from sqlalchemy import select
            result = await db.execute(
                select(Session).where(Session.id == session_id)
            )
            session = result.scalar_one_or_none()
            if session:
                connections = list(session.websocket_connections or [])
                connections.append({
                    "connected_at": datetime.utcnow().isoformat(),
                    "status": "active"
                })
                session.websocket_connections = connections
                session.last_activity = datetime.utcnow()
                await db.commit()
    
    def disconnect(self, websocket: WebSocket, session_id: str, agent_id: str):
        """Remove a WebSocket connection."""
        if session_id in self.active_connections:
            self.active_connections[session_id].discard(websocket)
            if not self.active_connections[session_id]:
                del self.active_connections[session_id]
        
        if agent_id in self.agent_connections:
            self.agent_connections[agent_id].discard(websocket)
            if not self.agent_connections[agent_id]:
                del self.agent_connections[agent_id]
    
    async def send_to_session(self, session_id: str, message: dict):
        """Send a message to all connections in a session."""
        if session_id not in self.active_connections:
            return
        
        disconnected = []
        for connection in self.active_connections[session_id]:
            try:
                await connection.send_json(message)
            except Exception:
                disconnected.append(connection)
        
        # Clean up disconnected
        for conn in disconnected:
            self.active_connections[session_id].discard(conn)
    
    async def send_to_agent(self, agent_id: str, message: dict):
        """Broadcast a message to all connections for an agent."""
        if agent_id not in self.agent_connections:
            return
        
        disconnected = []
        for connection in self.agent_connections[agent_id]:
            try:
                await connection.send_json(message)
            except Exception:
                disconnected.append(connection)
        
        # Clean up disconnected
        for conn in disconnected:
            for session_conns in self.active_connections.values():
                session_conns.discard(conn)
            self.agent_connections[agent_id].discard(conn)


manager = ConnectionManager()


@router.websocket("/{session_id}")
async def websocket_endpoint(websocket: WebSocket, session_id: str):
    """WebSocket endpoint for real-time session communication."""
    # Get agent_id from query params or auth
    agent_id = websocket.query_params.get("agent_id", "unknown")
    
    await manager.connect(websocket, session_id, agent_id)
    
    try:
        while True:
            # Receive message from client
            data = await websocket.receive_text()
            message = json.loads(data)
            
            msg_type = message.get("type", "unknown")
            
            if msg_type == "ping":
                await websocket.send_json({"type": "pong", "timestamp": datetime.utcnow().isoformat()})
            
            elif msg_type == "state_update":
                # Broadcast state update to other connections in session
                await manager.send_to_session(session_id, {
                    "type": "state_changed",
                    "agent_id": agent_id,
                    "data": message.get("data", {}),
                    "timestamp": datetime.utcnow().isoformat(),
                })
            
            elif msg_type == "memory_created":
                # Notify other connections of new memory
                await manager.send_to_session(session_id, {
                    "type": "memory_added",
                    "agent_id": agent_id,
                    "memory_id": message.get("memory_id"),
                    "timestamp": datetime.utcnow().isoformat(),
                })
            
            elif msg_type == "broadcast":
                # Broadcast to all agent connections
                await manager.send_to_agent(agent_id, {
                    "type": "broadcast",
                    "from_session": session_id,
                    "data": message.get("data", {}),
                    "timestamp": datetime.utcnow().isoformat(),
                })
            
            else:
                # Echo back for unknown types
                await websocket.send_json({
                    "type": "echo",
                    "original_type": msg_type,
                    "timestamp": datetime.utcnow().isoformat(),
                })
    
    except WebSocketDisconnect:
        manager.disconnect(websocket, session_id, agent_id)
    except Exception as e:
        manager.disconnect(websocket, session_id, agent_id)
        # Log error but don't crash
        print(f"WebSocket error for session {session_id}: {e}")
