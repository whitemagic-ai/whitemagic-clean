import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic/core/memory/shm_graph.py"

with open(file_path, "r") as f:
    content = f.read()

patch = """
    def __init__(self, name: str = "/whitemagic_graph_bridge"):
        self.name = name
        self._lock = threading.Lock()
        self._map_file = None
        self._shm = None
        self._count = 0
        self.uuid_to_id = {}
        self.id_to_uuid = {}
        self._next_id = 1
        
    def _get_or_create_id(self, uuid_str: str) -> int:
        if uuid_str not in self.uuid_to_id:
            self.uuid_to_id[uuid_str] = self._next_id
            self.id_to_uuid[self._next_id] = uuid_str
            self._next_id += 1
        return self.uuid_to_id[uuid_str]

    def initialize(self) -> None:
"""

content = re.sub(r'    def __init__\(self, name: str = "/whitemagic_graph_bridge"\):.*?    def initialize\(self\) -> None:', patch.strip('\n') + '\n', content, flags=re.DOTALL)

patch2 = """
    def sync_from_db(self, db_pool) -> None:
        \"\"\"Load topology from DB.\"\"\"
        self.initialize()
        with self._lock:
            with db_pool.connection() as conn:
                with conn:
                    # Let's get all edges
                    cur = conn.execute("SELECT source_id, target_id, strength FROM associations")
                    rows = cur.fetchall()
                    
                    self._count = 0
                    self.uuid_to_id.clear()
                    self.id_to_uuid.clear()
                    self._next_id = 1
                    
                    for row in rows:
                        src_id = self._get_or_create_id(row[0])
                        tgt_id = self._get_or_create_id(row[1])
                        
                        weight = row[2] or 1.0
                        offset = HEADER_SIZE + (self._count * SLOT_SIZE)
                        struct.pack_into("=iifi", self._map_file, offset, src_id, tgt_id, float(weight), 0)
                        self._count += 1
                        if self._count >= CAPACITY_EDGES:
                            logger.warning("SHM Graph Capacity reached!")
                            break
                                
                    struct.pack_into("=i", self._map_file, 12, self._count)
                    logger.info(f"Synchronized {self._count} graph edges to SHM.")
"""

content = re.sub(r'    def sync_from_db\(self, db_pool, uuid_to_id_map: dict\[str, int\]\) -> None:.*?logger\.info\(f"Synchronized \{self\._count\} graph edges to SHM\."\)', patch2.strip('\n'), content, flags=re.DOTALL)

with open(file_path, "w") as f:
    f.write(content)

print("shm_graph.py UUID mapping isolated and patched")
