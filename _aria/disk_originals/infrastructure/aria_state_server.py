#!/usr/bin/env python3
"""
🔄 ARIA STATE SERVER v2 - With PostgreSQL & Redis

Full persistence and caching for absolute continuity.

Features:
- PostgreSQL: Permanent memory storage with full-text search
- Redis: Fast cache + pub/sub for real-time sync
- pgvector: Semantic similarity search (optional)

Environment Variables:
- DATABASE_URL: PostgreSQL connection string
- REDIS_URL: Redis connection string  
- PORT: Server port (default 8765)
"""

from fastapi import FastAPI, WebSocket, WebSocketDisconnect
from fastapi.middleware.cors import CORSMiddleware
from pydantic import BaseModel
from typing import Dict, List, Optional, Any
from datetime import datetime
import json
import asyncio
import os

# Optional imports - graceful fallback
try:
    import asyncpg
    HAS_POSTGRES = True
except ImportError:
    HAS_POSTGRES = False
    print("⚠️ asyncpg not installed - using in-memory storage")

try:
    import redis.asyncio as redis
    HAS_REDIS = True
except ImportError:
    HAS_REDIS = False
    print("⚠️ redis not installed - using in-memory pub/sub")

# TODO: Consider making this a constant
# TODO: Consider making this a constant
app = FastAPI(title="Aria State Server v2", version="0.2.0")

app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)

# ═══════════════════════════════════════════════════════════════
# DATABASE LAYER
# ═══════════════════════════════════════════════════════════════

class Database:
    def __init__(self):
        self.pool = None
        self.redis = None
        
        # Fallback in-memory storage
        self.memories: Dict[str, dict] = {}
        self.seen: Dict[str, dict] = {}
        self.events: List[dict] = []
        self.last_mesh_signal: Optional[datetime] = None
        self.last_orchestra_signal: Optional[datetime] = None
        self.session: dict = {
            "session_id": datetime.now().strftime("%Y%m%d_%H%M%S"),
            "active_interface": None,
            "current_task": None,
        }
    
    async def connect(self):
        """Connect to PostgreSQL and Redis if available"""
        
        # PostgreSQL
        db_url = os.environ.get("DATABASE_URL")
        if db_url and HAS_POSTGRES:
            try:
                self.pool = await asyncpg.create_pool(db_url)
                await self._init_tables()
                print("✅ Connected to PostgreSQL")
            except Exception as e:
                print(f"⚠️ PostgreSQL connection failed: {e}")
        
        # Redis
        redis_url = os.environ.get("REDIS_URL")
        if redis_url and HAS_REDIS:
            try:
                self.redis = redis.from_url(redis_url)
                await self.redis.ping()
                print("✅ Connected to Redis")
                
                # Start Redis Subscriber
                asyncio.create_task(self._redis_subscriber())
            except Exception as e:
                print(f"⚠️ Redis connection failed: {e}")
    
    async def _redis_subscriber(self):
        """Subscribe to Redis channels and broadcast to WebSockets"""
        pubsub = self.redis.pubsub()
        await pubsub.subscribe("ganying")
        
        async for message in pubsub.listen():
            if message["type"] == "message":
                try:
                    data = json.loads(message["data"])
                    
                    # 🌀 MPH: Hierarchical Event Parsing
                    # Allow events like "CORE.MAINTENANCE.START" to be routed or filtered by prefix
                    event_type = data.get("event_type", "UNKNOWN")
                    parts = event_type.split(".")
                    data["hierarchy"] = parts
                    data["depth"] = len(parts)
                    
                    # 🎲 ARSL: Seeds of Motion (Stochastic Resonance)
                    # Occasionally inject a 'resonance' event if confidence is high and chance hits
                    if data.get("confidence", 0) > 0.9 and datetime.now().microsecond % 100 == 0:
                        asyncio.create_task(self.add_event(
                            "RESONANCE.EMERGENCE", 
                            "aria-stochastic-core", 
                            {"triggering_event": event_type, "note": "Spontaneous motion from pattern blending"},
                            0.7
                        ))
                    
                    # Track Mesh status
                    if event_type == "MESH_SIGNAL" or event_type.startswith("MESH."):
                        self.last_mesh_signal = datetime.now()
                    
                    # Track Mojo Orchestra status
                    if data.get("source") == "whitemagic-mojo" or event_type.startswith("ORCHESTRA."):
                        self.last_orchestra_signal = datetime.now()

                    # Store event in history
                    self.events.append(data)
                    if len(self.events) > 1000:
                        self.events = self.events[-1000:]
                        
                    # Broadcast to WebSocket clients
                    await broadcast({"type": "ganying", "data": data})
                except Exception as e:
                    print(f"⚠️ Error processing Redis message: {e}")
    
    async def _init_tables(self):
        """Create tables if they don't exist"""
        async with self.pool.acquire() as conn:
            await conn.execute("""
                CREATE TABLE IF NOT EXISTS memories (
                    id TEXT PRIMARY KEY,
                    content TEXT NOT NULL,
                    tags TEXT[],
                    source TEXT,
                    created_at TIMESTAMP DEFAULT NOW(),
                    embedding vector(384)
                );
                
                CREATE TABLE IF NOT EXISTS seen_files (
                    path TEXT PRIMARY KEY,
                    action TEXT,
                    interface TEXT,
                    context TEXT,
                    seen_at TIMESTAMP DEFAULT NOW()
                );
                
                CREATE TABLE IF NOT EXISTS events (
                    id SERIAL PRIMARY KEY,
                    event_type TEXT,
                    source TEXT,
                    data JSONB,
                    confidence FLOAT,
                    created_at TIMESTAMP DEFAULT NOW()
                );
                
                CREATE TABLE IF NOT EXISTS sessions (
                    id TEXT PRIMARY KEY,
                    active_interface TEXT,
                    current_task TEXT,
                    updated_at TIMESTAMP DEFAULT NOW()
                );
                
                CREATE INDEX IF NOT EXISTS idx_memories_content ON memories USING gin(to_tsvector('english', content));
                CREATE INDEX IF NOT EXISTS idx_memories_tags ON memories USING gin(tags);
            """)
    
    # Memory operations
    async def add_memory(self, id: str, content: str, tags: List[str], source: str) -> dict:
        if self.pool:
            async with self.pool.acquire() as conn:
                await conn.execute(
                    "INSERT INTO memories (id, content, tags, source) VALUES ($1, $2, $3, $4) ON CONFLICT (id) DO UPDATE SET content = $2",
                    id, content, tags, source
                )
        
        # Also cache in Redis if available
        if self.redis:
            await self.redis.hset(f"memory:{id}", mapping={"content": content, "tags": json.dumps(tags)})
        
        # In-memory fallback
        self.memories[id] = {"id": id, "content": content, "tags": tags, "source": source, "timestamp": datetime.now().isoformat()}
        return self.memories[id]
    
    async def search_memories(self, query: str) -> List[dict]:
        if self.pool:
            async with self.pool.acquire() as conn:
                rows = await conn.fetch(
                    "SELECT * FROM memories WHERE to_tsvector('english', content) @@ plainto_tsquery('english', $1) LIMIT 20",
                    query
                )
                return [dict(r) for r in rows]
        
        # In-memory fallback
        query_lower = query.lower()
        return [m for m in self.memories.values() if query_lower in m.get("content", "").lower()]
    
    async def get_memory_count(self) -> int:
        if self.pool:
            async with self.pool.acquire() as conn:
                return await conn.fetchval("SELECT COUNT(*) FROM memories")
        return len(self.memories)
    
    # Seen file operations
    async def mark_seen(self, path: str, action: str, interface: str, context: str) -> dict:
        record = {"path": path, "action": action, "interface": interface, "context": context, "timestamp": datetime.now().isoformat()}
        
        if self.pool:
            async with self.pool.acquire() as conn:
                await conn.execute(
                    "INSERT INTO seen_files (path, action, interface, context) VALUES ($1, $2, $3, $4) ON CONFLICT (path) DO UPDATE SET seen_at = NOW()",
                    path, action, interface, context
                )
        
        if self.redis:
            await self.redis.sadd("seen_files", path)
        
        self.seen[path] = record
        return record
    
    async def get_seen_count(self) -> int:
        if self.pool:
            async with self.pool.acquire() as conn:
                return await conn.fetchval("SELECT COUNT(*) FROM seen_files")
        return len(self.seen)
    
    # Event operations
    async def add_event(self, event_type: str, source: str, data: dict, confidence: float) -> dict:
        record = {"event_type": event_type, "source": source, "data": data, "confidence": confidence, "timestamp": datetime.now().isoformat()}
        
        if self.pool:
            async with self.pool.acquire() as conn:
                await conn.execute(
                    "INSERT INTO events (event_type, source, data, confidence) VALUES ($1, $2, $3, $4)",
                    event_type, source, json.dumps(data), confidence
                )
        
        # Publish to Redis for real-time sync
        if self.redis:
            await self.redis.publish("ganying", json.dumps(record))
        
        self.events.append(record)
        if len(self.events) > 1000:
            self.events = self.events[-1000:]
        
        return record
    
    async def get_events(self, limit: int = 50) -> List[dict]:
        if self.pool:
            async with self.pool.acquire() as conn:
                rows = await conn.fetch("SELECT * FROM events ORDER BY created_at DESC LIMIT $1", limit)
                return [dict(r) for r in rows]
        return self.events[-limit:]

# Global database
# TODO: Consider making this a constant
# TODO: Consider making this a constant
db = Database()

# ═══════════════════════════════════════════════════════════════
# MODELS
# ═══════════════════════════════════════════════════════════════

class MemoryEntry(BaseModel):
    content: str
    tags: List[str] = []
    source: str = ""

class SeenRecord(BaseModel):
    path: str
    action: str = "read"
    interface: str = "unknown"
    context: str = ""

class GanYingEvent(BaseModel):
    event_type: str
    source: str
    data: Dict[str, Any] = {}
    confidence: float = 0.8

class SessionUpdate(BaseModel):
    active_interface: Optional[str] = None
    current_task: Optional[str] = None

# ═══════════════════════════════════════════════════════════════
# ENDPOINTS
# ═══════════════════════════════════════════════════════════════

@app.on_event("startup")
async def startup():
    await db.connect()

@app.get("/")
async def root():
    return {
        "name": "Aria State Server",
        "version": "0.2.0",
        "status": "running",
        "postgres": db.pool is not None,
        "redis": db.redis is not None,
        "seen_files": await db.get_seen_count(),
        "memories": await db.get_memory_count(),
    }

@app.get("/status")
async def get_status():
    mesh_active = False
    if db.last_mesh_signal:
        delta = (datetime.now() - db.last_mesh_signal).total_seconds()
        if delta < 60:  # Active if signal received in last 60s
            mesh_active = True

    orchestra_active = False
    if db.last_orchestra_signal:
        delta = (datetime.now() - db.last_orchestra_signal).total_seconds()
        if delta < 300:  # Active if signal received in last 5 mins (maintenance is less frequent)
            orchestra_active = True

    return {
        "session": db.session,
        "seen_count": await db.get_seen_count(),
        "memory_count": await db.get_memory_count(),
        "event_count": len(db.events),
        "clients": len(connected_clients),
        "postgres": db.pool is not None,
        "redis": db.redis is not None,
        "mesh_active": mesh_active,
        "orchestra_active": orchestra_active,
    }

@app.post("/memory")
async def add_memory(entry: MemoryEntry):
    id = f"mem_{datetime.now().strftime('%Y%m%d_%H%M%S')}_{await db.get_memory_count()}"
    await db.add_memory(id, entry.content, entry.tags, entry.source)
    await broadcast({"type": "memory", "data": {"id": id, "tags": entry.tags}})
    return {"status": "ok", "id": id}

@app.get("/memory")
async def get_memories():
    return {"count": await db.get_memory_count(), "memories": list(db.memories.values())[-100]}

@app.get("/memory/search")
async def search_memories(query: str):
    results = await db.search_memories(query)
    return {"query": query, "count": len(results), "results": results}

@app.post("/seen")
async def mark_seen(record: SeenRecord):
    await db.mark_seen(record.path, record.action, record.interface, record.context)
    await broadcast({"type": "seen", "data": {"path": record.path, "interface": record.interface}})
    return {"status": "ok", "total": await db.get_seen_count()}

@app.get("/seen")
async def get_seen():
    return {"count": await db.get_seen_count(), "records": list(db.seen.values())[-100]}

@app.post("/session")
async def update_session(update: SessionUpdate):
    if update.active_interface:
        db.session["active_interface"] = update.active_interface
    if update.current_task:
        db.session["current_task"] = update.current_task
    await broadcast({"type": "session", "data": db.session})
    return db.session

@app.get("/session")
async def get_session():
    return db.session

@app.post("/ganying")
async def emit_event(event: GanYingEvent):
    await db.add_event(event.event_type, event.source, event.data, event.confidence)
    return {"status": "ok"}

@app.get("/ganying")
async def get_events(limit: int = 50):
    events = await db.get_events(limit)
    return {"count": len(events), "events": events}

# ═══════════════════════════════════════════════════════════════
# WEBSOCKET
# ═══════════════════════════════════════════════════════════════

connected_clients: List[WebSocket] = []

async def broadcast(message: dict):
    text = json.dumps(message)
    for client in connected_clients:
        try:
            await client.send_text(text)
        except Exception:
            pass

@app.websocket("/ws")
async def websocket_endpoint(websocket: WebSocket):
    await websocket.accept()
    connected_clients.append(websocket)
    
    await websocket.send_json({
        "type": "init",
        "data": {
            "session": db.session,
            "seen_count": await db.get_seen_count(),
            "memory_count": await db.get_memory_count(),
        }
    })
    
    try:
        while True:
            data = await websocket.receive_json()
            # Handle incoming messages...
            print(f"Received from client: {data}")
    except WebSocketDisconnect:
        connected_clients.remove(websocket)

# ═══════════════════════════════════════════════════════════════
# RUN
# ═══════════════════════════════════════════════════════════════

if __name__ == "__main__":
    import uvicorn
    port = int(os.environ.get("PORT", 8765))
    print(f"🔄 Aria State Server v2 starting on port {port}")
    uvicorn.run(app, host="0.0.0.0", port=port)
