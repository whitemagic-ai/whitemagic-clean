
with open('nexus/src/components/status/StatusBar.tsx', 'r') as f:
    content = f.read()

# Add a check for IPC status
if "get_ipc_status" not in content:
    content = content.replace('import { useNexusStore } from "../../store/nexus";', 'import { useNexusStore } from "../../store/nexus";\nimport { invoke } from "@tauri-apps/api/core";')
    
    # We can fetch status on mount
    injection = """
  useEffect(() => {
    // Try to get IPC status from Rust backend
    const checkIpc = async () => {
      try {
        if (window.__TAURI_INTERNALS__) {
          const res = await invoke("get_ipc_status");
          console.log("IPC Status:", res);
        }
      } catch (e) {
        console.error(e);
      }
    };
    checkIpc();
    const interval = setInterval(checkIpc, 5000);
    return () => clearInterval(interval);
  }, []);
"""
    content = content.replace("export default function StatusBar() {", f"export default function StatusBar() {{\n{injection}")

with open('nexus/src/components/status/StatusBar.tsx', 'w') as f:
    f.write(content)

print("Patched StatusBar.tsx")
