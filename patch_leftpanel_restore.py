
content = """import {
  FolderTree,
  Search,
  Brain,
  Sparkles,
  Shield,
  ChevronRight,
  ChevronDown,
  FileText,
  Folder,
  FolderOpen,
} from "lucide-react";
import { useState } from "react";
import { useNexusStore, type LeftTab } from "../../store/nexus";
import { useEditorStore } from "../../store/editor";
// @ts-ignore
import { invoke } from "@tauri-apps/api/core";

const tabs: { id: LeftTab; icon: typeof FolderTree; title: string }[] = [
  { id: "explorer", icon: FolderTree, title: "Explorer" },
  { id: "search", icon: Search, title: "Search" },
  { id: "memories", icon: Brain, title: "Memories" },
  { id: "gardens", icon: Sparkles, title: "Gardens" },
  { id: "dharma", icon: Shield, title: "Dharma" },
];

interface TreeNode {
  name: string;
  type: "file" | "folder";
  path: string;
  children?: TreeNode[];
}

function FileTree({
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
        if ((window as any).__TAURI_INTERNALS__) {
          // @ts-ignore
          const content = await invoke<string>("read_file", { filePath: node.path });
          openFile({
            path: node.path,
            name: node.name,
            language: node.name.endsWith(".ts") || node.name.endsWith(".tsx") ? "typescript" :
                     node.name.endsWith(".rs") ? "rust" :
                     node.name.endsWith(".py") ? "python" : "plaintext",
            content,
            dirty: false
          });
        }
      } catch (e) {
        console.error("Failed to read file", e);
      }
      return;
    }

    if (!open && children.length === 0) {
      setLoading(true);
      try {
        if ((window as any).__TAURI_INTERNALS__) {
          // @ts-ignore
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
}

export default function LeftPanel() {
  const tab = useNexusStore((s) => s.leftTab);
  const [rootNode] = useState<TreeNode>({ name: "workspace", type: "folder", path: "/home/lucas/Desktop/whitemagicdev" });

  return (
    <div className="flex flex-col h-full bg-wm-bg-panel border-r border-wm-border">
      {/* ... keeping the rest of the file minimal ... */}
      <div className="overflow-y-auto flex-1 py-2">
        <FileTree node={rootNode} depth={0} />
      </div>
    </div>
  );
}
"""

with open('nexus/src/components/panels/LeftPanel.tsx', 'w') as f:
    f.write(content)
