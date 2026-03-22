
with open('whitemagic/cascade/adaptive_portal.py') as f:
    content = f.read()

# Make sure holographic context injector is imported
if "HolographicContextInjector" not in content:
    content = content.replace("from typing import Any", "from typing import Any\nfrom whitemagic.cascade.holographic_context import get_holographic_injector")

# Inject context into the context dictionary gathered at start of invoke
replacement = """        start_time = datetime.now()

        # 1. Gather context
        context = self.synthesizer.gather()

        # 1.5 Inject Holographic Context
        try:
            injector = get_holographic_injector()
            context.attributes["holographic_system_map"] = injector.generate_system_prompt_injection(str(params))
        except Exception as e:
            logger.debug(f"Holographic injection failed: {e}")"""

content = content.replace("""        start_time = datetime.now()

        # 1. Gather context
        context = self.synthesizer.gather()""", replacement)

with open('whitemagic/cascade/adaptive_portal.py', 'w') as f:
    f.write(content)

print("Patched adaptive_portal.py")
