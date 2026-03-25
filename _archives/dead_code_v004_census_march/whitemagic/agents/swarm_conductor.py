import logging
import threading
from typing import Dict, Any, List
from whitemagic.agents.swarm import AgentSwarm, SwarmPlan, SubTask

logger = logging.getLogger(__name__)

class SwarmConductor:
    """Phase 6.3: Asynchronous Swarm Delegation via Iceoryx2.
    
    Instead of executing tasks synchronously in Python, the Conductor decomposes
    a massive task (e.g. refactoring 50 files) and broadcasts the subtasks via
    Iceoryx2 shared memory (`wm/commands`).
    
    Zig or WASM parallel graph walkers (or other Python clones) listening on 
    the channel will pick up the subtasks, execute them concurrently, and 
    publish results back to `wm/events`.
    
    The AI acts as the 'Conductor', merely tracking the completion of the SwarmPlan.
    """
    
    def __init__(self):
        self.swarm = AgentSwarm()
        self._results: Dict[str, Any] = {}
        self._lock = threading.Lock()
        
        self._ipc_available = False
        try:
            from whitemagic.core.ipc_bridge import publish_json, get_status
            status = get_status()
            if status.get("initialized") or status.get("backend") == "iceoryx2":
                self._publish_json = publish_json
                self._ipc_available = True
        except ImportError:
            pass

    def delegate_task(self, goal: str, files: List[str]) -> SwarmPlan:
        """Decompose a large task and delegate via IPC."""
        plan = self.swarm.decompose(goal, hints=["parallel", "code"])
        
        # Override the heuristic decomposition for file-based parallel tasks
        if files:
            plan.subtasks = []
            for i, f in enumerate(files):
                task = SubTask(
                    id=f"{plan.id}_file_{i}",
                    description=f"Process file: {f}",
                    required_capabilities=["file_ops", "parallel_walk"]
                )
                plan.subtasks.append(task)
                self.swarm.add_plan(plan)
        
        if self._ipc_available:
            try:
                self._publish_json("wm/commands", {
                    "type": "swarm_delegation",
                    "plan_id": plan.id,
                    "goal": goal,
                    "task_count": len(plan.subtasks),
                    "subtasks": [{"id": t.id, "desc": t.description} for t in plan.subtasks]
                })
                logger.info(f"Delegated {len(plan.subtasks)} tasks via Iceoryx2 IPC")
            except Exception as e:
                logger.warning(f"Failed to publish swarm delegation: {e}")
                
        return plan
        
    def check_status(self, plan_id: str) -> Dict[str, Any]:
        """Check the status of a delegated swarm plan."""
        plan = self.swarm.get_plan(plan_id)
        if not plan:
            return {"error": "Plan not found"}
            
        completed = sum(1 for t in plan.subtasks if t.status.value == "completed")
        total = len(plan.subtasks)
        
        return {
            "plan_id": plan.id,
            "progress": f"{completed}/{total}",
            "percent": (completed / total * 100) if total > 0 else 100,
            "status": "completed" if completed == total else "running"
        }

_conductor_instance = None
def get_swarm_conductor() -> SwarmConductor:
    global _conductor_instance
    if _conductor_instance is None:
        _conductor_instance = SwarmConductor()
    return _conductor_instance
