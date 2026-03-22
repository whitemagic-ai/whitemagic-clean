
with open('whitemagic/tools/dispatch_table.py') as f:
    content = f.read()

if "mw_sutra_auto_execute" not in content:
    content = content.replace("mw_tool_permissions,", "mw_tool_permissions,\n        mw_sutra_auto_execute,")
    content = content.replace('p.use("governor",         mw_governor)', 'p.use("governor",         mw_governor)\n    p.use("sutra_auto_execute", mw_sutra_auto_execute)')

with open('whitemagic/tools/dispatch_table.py', 'w') as f:
    f.write(content)

print("Patched dispatch_table.py")
