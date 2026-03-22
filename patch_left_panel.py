import re

with open('nexus/src/components/panels/LeftPanel.tsx') as f:
    content = f.read()

# Make it use tauri API for fs
new_content = content.replace('import { useState } from "react";', 'import { useState, useEffect } from "react";\nimport { invoke } from "@tauri-apps/api/core";')

# Update TreeNode type
new_content = new_content.replace("""interface TreeNode {
  name: string;
  type: "file" | "folder";
  children?: TreeNode[];
}""", """interface TreeNode {
  name: string;
  type: "file" | "folder";
  path: string;
  children?: TreeNode[];
}""")

# Replace FileTree component to load dynamically
filetree_replacement = """function FileTree({
  node,
  depth = 0,
}: {
  node: TreeNode;
  depth?: number;
}) {
  const [open, setOpen] = useState(depth === 0);
  const [children, setChildren] = useState<TreeNode[]>(node.children || []);
  const [loading, setLoading] = useState(false);
  const openFile = useEditorStore((s) => s.openFile);

  const toggleOpen = async () => {
    if (node.type === "file") {
      try {
        const content = await invoke<string>("read_file", { filePath: node.path });
        openFile({
          id: node.path,
          name: node.name,
          language: node.name.endsWith(".ts") || node.name.endsWith(".tsx") ? "typescript" :
                   node.name.endsWith(".rs") ? "rust" :
                   node.name.endsWith(".py") ? "python" : "plaintext",
          content,
        });
      } catch (e) {
        console.error("Failed to read file", e);
      }
      return;
    }

    if (!open && children.length === 0) {
      setLoading(true);
      try {
        if (window.__TAURI_INTERNALS__) {
          const files = await invoke<TreeNode[]>("list_directory", { dirPath: node.path });
          setChildren(files);
        }
      } catch (e) {
        console.error("Failed to load dir", e);
      } finally {
        setLoading(false);
      }
    }
    setOpen(!open);
  };

  return (
    <div className="select-none">
      <div
        className={`flex items-center gap-1.5 px-2 py-1 cursor-pointer hover:bg-gray-800 transition-colors
          ${node.type === "file" ? "text-gray-300" : "text-gray-200"}`}
        style={{ paddingLeft: `${depth * 12 + 8}px` }}
        onClick={toggleOpen}
      >
        {node.type === "folder" && (
          <span className="text-gray-500">
            {open ? (
              <ChevronDown className="w-3.5 h-3.5" />
            ) : (
              <ChevronRight className="w-3.5 h-3.5" />
            )}
          </span>
        )}
        {node.type === "folder" ? (
          open ? (
            <FolderOpen className="w-4 h-4 text-blue-400" />
          ) : (
            <Folder className="w-4 h-4 text-blue-400" />
          )
        ) : (
          <FileText className="w-4 h-4 text-gray-400 ml-5" />
        )}
        <span className="text-sm truncate">{node.name}</span>
        {loading && <span className="text-xs text-gray-500">...</span>}
      </div>

      {open && node.type === "folder" && (
        <div>
          {children.map((child, i) => (
            <FileTree
              key={i}
              node={child}
              depth={depth + 1}
            />
          ))}
        </div>
      )}
    </div>
  );
}"""

new_content = re.sub(r'function FileTree\(\{[\s\S]*?</div>\n      \)\}\n    </div>\n  \);\n\}', filetree_replacement, new_content)

# We need an overarching state to hold the root workspace
workspace_injection = """
  const [rootNode, setRootNode] = useState<TreeNode>({
    name: "workspace",
    type: "folder",
    path: "/home/lucas/Desktop/whitemagicdev"
  });

  useEffect(() => {
    // We start with root unloaded, FileTree will load it
  }, []);
"""

new_content = new_content.replace('const tab = useNexusStore((s) => s.leftTab);', 'const tab = useNexusStore((s) => s.leftTab);\n' + workspace_injection)
new_content = re.sub(r'<div className="overflow-y-auto flex-1 py-2">\n        \{SAMPLE_TREE\.map\(\(node, i\) => \(\n          <FileTree key=\{i\} node=\{node\} />\n        \)\)\}\n      </div>', '<div className="overflow-y-auto flex-1 py-2">\n        <FileTree node={rootNode} depth={0} />\n      </div>', new_content)

with open('nexus/src/components/panels/LeftPanel.tsx', 'w') as f:
    f.write(new_content)

print("Patched LeftPanel.tsx")
