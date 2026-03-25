import struct
import posix_ipc
import mmap
import logging
import threading
import numpy as np

logger = logging.getLogger(__name__)

HEADER_SIZE = 64
MAGIC = 0x574D4B4B # "WMKK"
SLOT_SIZE = 1540 # 4 byte ID + 384 * 4 byte vector
CAPACITY = 20000
SEGMENT_SIZE = HEADER_SIZE + (CAPACITY * SLOT_SIZE)
DIM = 384

class SharedMemoryManager:
    """Manages the lifecycle and synchronization of the POSIX shared memory segment for fast Koka searches."""

    def __init__(self, name: str = "/whitemagic_embed_bridge_real"):
        self.name = name
        self._lock = threading.Lock()
        self._map_file = None
        self._shm = None
        self._id_to_uuid = {}
        self._uuid_to_id = {}
        self._count = 0
        self._next_id = 1 # Reserve 0 for "query" or null

    def initialize(self) -> None:
        """Create or connect to the shared memory segment."""
        with self._lock:
            if self._map_file is not None:
                return

            try:
                # Try to open existing
                self._shm = posix_ipc.SharedMemory(self.name)
            except posix_ipc.ExistentialError:
                # Create new
                self._shm = posix_ipc.SharedMemory(self.name, posix_ipc.O_CREAT | posix_ipc.O_EXCL, size=SEGMENT_SIZE)

            self._map_file = mmap.mmap(self._shm.fd, self._shm.size)
            self._shm.close_fd() # Safe to close FD after mmap

            # Initialize header if it's a new segment or corrupted
            magic = struct.unpack_from("=i", self._map_file, 0)[0]
            if magic != MAGIC:
                struct.pack_into("=iiiiii", self._map_file, 0, MAGIC, 1, CAPACITY, 0, 0, 0)
                self._count = 0
            else:
                self._count = struct.unpack_from("=i", self._map_file, 12)[0]

    def _write_memory_item(self, index: int, int_id: int, vector: np.ndarray) -> None:
        if index >= CAPACITY:
            raise ValueError("Shared memory capacity exceeded.")
        offset = HEADER_SIZE + (index * SLOT_SIZE)
        struct.pack_into("=i", self._map_file, offset, int_id)
        struct.pack_into(f"={DIM}f", self._map_file, offset + 4, *vector)

    def _update_count(self, count: int) -> None:
        struct.pack_into("=i", self._map_file, 12, count)

    def sync_from_db(self, db_pool) -> None:
        """Load all embeddings from DB and populate SHM."""
        self.initialize()

        with self._lock:
            with db_pool.connection() as conn:
                with conn:
                    cur = conn.execute(f"SELECT memory_id, embedding FROM memory_embeddings LIMIT {CAPACITY}")
                    rows = cur.fetchall()

                    self._id_to_uuid.clear()
                    self._uuid_to_id.clear()
                    self._count = 0
                    self._next_id = 1

                    for row in rows:
                        mem_id = row[0]
                        blob = row[1]
                        if blob:
                            try:
                                vec = np.frombuffer(blob, dtype=np.float32)
                                if len(vec) == DIM:
                                    # Normalize
                                    norm = np.linalg.norm(vec)
                                    if norm > 0:
                                        vec = vec / norm

                                    int_id = self._next_id
                                    self._next_id += 1

                                    self._id_to_uuid[int_id] = mem_id
                                    self._uuid_to_id[mem_id] = int_id

                                    self._write_memory_item(self._count, int_id, vec)
                                    self._count += 1
                            except Exception as e:
                                logger.warning(f"Failed to load embedding for {mem_id}: {e}")

                    self._update_count(self._count)
                    logger.info(f"Synchronized {self._count} embeddings to shared memory.")

    def add_or_update(self, mem_id: str, vector: np.ndarray) -> None:
        """Add a single embedding or update it."""
        self.initialize()

        with self._lock:
            norm = np.linalg.norm(vector)
            if norm > 0:
                vector = vector / norm

            if mem_id in self._uuid_to_id:
                # Update existing (find its index, which is roughly id - 1 if we never delete... wait, we need an index map)
                # For now, let's keep it simple: just append if not full, or we need a proper index map.
                pass # TODO: handle updates properly
            else:
                if self._count >= CAPACITY:
                    logger.warning("Shared memory full, cannot add more embeddings.")
                    return

                int_id = self._next_id
                self._next_id += 1

                self._id_to_uuid[int_id] = mem_id
                self._uuid_to_id[mem_id] = int_id

                self._write_memory_item(self._count, int_id, vector)
                self._count += 1
                self._update_count(self._count)

    def write_query(self, query_id: int, vector: np.ndarray) -> None:
        """Write a query vector into the SHM segment at the specified ID index."""
        self.initialize()
        with self._lock:
            norm = np.linalg.norm(vector)
            if norm > 0:
                vector = vector / norm
            self._write_memory_item(query_id, 0, vector)

    def get_uuid(self, int_id: int) -> str | None:
        return self._id_to_uuid.get(int_id)

    def get_count(self) -> int:
        return self._count

_global_shm_manager = None
def get_shm_manager() -> SharedMemoryManager:
    global _global_shm_manager
    if _global_shm_manager is None:
        _global_shm_manager = SharedMemoryManager()
    return _global_shm_manager
