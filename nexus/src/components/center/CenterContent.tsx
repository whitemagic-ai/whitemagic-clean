import { useNexusStore } from "../../store/nexus";
import MonacoEditor from "./MonacoEditor";
import HarmonyDashboard from "./HarmonyDashboard";
import MemoryGraph from "./MemoryGraph";
import ToolGraph from "./ToolGraph";
import HolographicView from "./HolographicView";
import GlobalSearch from "./GlobalSearch";
import GhostTextAutocompletion from "./GhostTextAutocompletion";

export default function CenterContent() {
  const tab = useNexusStore((s) => s.centerTab);

  return (
    <>
      <GhostTextAutocompletion />
    <div className="h-full overflow-hidden">
      {tab === "editor" && <MonacoEditor />}
      {tab === "dashboard" && <HarmonyDashboard />}
      {tab === "graph" && <MemoryGraph />}
      {tab === "tools" && <ToolGraph />}
      {tab === "holographic" && <HolographicView />}
      {/* @ts-ignore */}
      {tab === "search" && <GlobalSearch />}
    </div>
    </>
  );
}
