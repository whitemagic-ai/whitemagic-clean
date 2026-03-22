import re

with open('nexus/src/store/editor.ts') as f:
    content = f.read()

# Add a save function
if "saveFile: (path: string) => Promise<void>;" not in content:
    content = content.replace("updateContent: (path: string, content: string) => void;", "updateContent: (path: string, content: string) => void;\n  saveFile: (path: string) => Promise<void>;")

    # Needs to import invoke
    content = content.replace('import { create } from "zustand";', 'import { create } from "zustand";\nimport { invoke } from "@tauri-apps/api/core";')

    save_impl = """
  updateContent: (path, content) =>
    set((state) => ({
      openFiles: state.openFiles.map((f) =>
        f.path === path ? { ...f, content, dirty: true } : f
      ),
    })),

  saveFile: async (path) => {
    const state = useEditorStore.getState();
    const file = state.openFiles.find((f) => f.path === path);
    if (!file || !file.dirty) return;

    try {
      if (window.__TAURI_INTERNALS__) {
        // Need to add this endpoint to Rust
        await invoke("write_file", { filePath: path, content: file.content });
        set((s) => ({
          openFiles: s.openFiles.map((f) =>
            f.path === path ? { ...f, dirty: false } : f
          ),
        }));
      }
    } catch (e) {
      console.error("Failed to save file", e);
    }
  },"""
    content = re.sub(r'  updateContent: \(path, content\) =>[\s\S]*?\}\)\),', save_impl, content)

with open('nexus/src/store/editor.ts', 'w') as f:
    f.write(content)

print("Patched editor.ts with saveFile")
