"""
Phase Enforcer (G007)
=====================

Ensures that actions taken by the agent align with the current Wu Xing phase.
"""

from whitemagic.core.wuxing_scheduler import WuXingScheduler

class PhaseEnforcer:
    """
    Enforces phase discipline.
    """
    
    def __init__(self, scheduler: WuXingScheduler):
        self.scheduler = scheduler

    def check_action(self, action_type: str) -> bool:
        """
        Check if an action is allowed in the current phase.
        Returns True if allowed, False if blocked.
        """
        allowed = self.scheduler.get_allowed_actions()
        
        # If action_type is not in our known list, we might default to allow or block.
        # For safety, let's assume we map known tools to these types.
        # If the action isn't strictly categorized, we might let it pass or warn.
        # For this implementation, we'll check exact match or partial match.
        
        if not allowed:
             # Should not happen if configured correctly
             return True
             
        # Simple permissive check: if any allowed keyword is in action_type
        # E.g. "write_to_file" matches "write_file" loosely? 
        # Better to have exact mapping.
        
        # Map tool names to generic action types
        generic_type = self._map_tool_to_action(action_type)
        if not generic_type:
            return True # Allow unknown actions
            
        return generic_type in allowed

    def _map_tool_to_action(self, tool_name: str) -> str:
        """Map actual tool names to abstract action types."""
        mapping = {
            "write_to_file": "write_file",
            "run_command": "execute_command",
            "read_file": "plan", # reading is usually safe everywhere, but let's say it's recon
            "todo_list": "plan",
            "deploy_clones": "deploy_clones",
            # Add more mappings as needed
        }
        return mapping.get(tool_name, "")
