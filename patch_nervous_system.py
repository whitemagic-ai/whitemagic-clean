import re

with open('whitemagic/core/autonomous/unified_nervous_system.py', 'r') as f:
    content = f.read()

# Add the dream hook
if "get_background_dreamer" not in content:
    content = content.replace("import logging", "import logging\nfrom whitemagic.core.dreaming.background_dreamer import get_background_dreamer")
    
    # Wire it into the dream handler
    replacement = """    def dream_handler(event: BiologicalEvent) -> None:
        if event.event_type == "coherence.critical" or event.event_type == "dream.trigger":
            logger.info("💤 Dream: Triggering emergency or idle dream cycle")
            try:
                dreamer = get_background_dreamer()
                dreamer.trigger_dream_cycle()
            except Exception as e:
                logger.error(f"Failed to trigger background dreamer: {e}")"""
                
    content = re.sub(r'    def dream_handler\(event: BiologicalEvent\) -> None:[\s\S]*?logger.info\("💤 Dream: Triggering emergency dream cycle"\)', replacement, content)

with open('whitemagic/core/autonomous/unified_nervous_system.py', 'w') as f:
    f.write(content)

print("Patched unified_nervous_system.py to use BackgroundDreamer")
