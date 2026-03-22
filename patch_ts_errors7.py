import re

with open('nexus/src/components/panels/LeftPanel.tsx') as f:
    content = f.read()

# Remove the unused TreeItem
content = re.sub(r'function TreeItem\(\{[\s\S]*?</div>\n    </div>\n  \);\n\}', '', content)

# Inject the rootNode state inside the LeftPanel component
if "const [rootNode" not in content:
    content = content.replace("const tab = useNexusStore((s) => s.leftTab);", 'const tab = useNexusStore((s) => s.leftTab);\n  const [rootNode] = useState<TreeNode>({ name: "workspace", type: "folder", path: "/workspace/whitemagic" });')

# The `FileTree` component we injected earlier seems to have been lost or we injected it into the wrong place. Let's make sure it exists.
filetree = """
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
"""

if "function FileTree" not in content:
    content = content.replace("export default function LeftPanel() {", filetree + "\nexport default function LeftPanel() {")

with open('nexus/src/components/panels/LeftPanel.tsx', 'w') as f:
    f.write(content)

with open('nexus/src/components/center/GlobalSearch.tsx') as f:
    content = f.read()

# Replace openFile with hardcoded 'path' instead of variable since it was failing TS type checking
content = re.sub(r'openFile\(\{[\s\S]*?dirty: false\n\s*\}\);', 'openFile({\n          path: res.file,\n          name: fileName,\n          language: fileName.endsWith(".ts") || fileName.endsWith(".tsx") ? "typescript" : \n                   fileName.endsWith(".rs") ? "rust" : \n                   fileName.endsWith(".py") ? "python" : "plaintext",\n          content,\n          dirty: false\n        });', content)

with open('nexus/src/components/center/GlobalSearch.tsx', 'w') as f:
    f.write(content)

print("Patched LeftPanel.tsx and GlobalSearch.tsx TS errors")
