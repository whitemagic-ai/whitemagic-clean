import { useState, useEffect } from 'react';
import Header from "./Header";
import PanelLayout from "./panels/PanelLayout";
import LeftPanel from "./panels/LeftPanel";
import RightPanel from "./panels/RightPanel";
import BottomPanel from "./panels/BottomPanel";
import CenterContent from "./center/CenterContent";
import StatusBar from "./status/StatusBar";
import CommandPalette from "./CommandPalette";
import RadialPalette from "./RadialPalette";

export default function AppWithPalette() {
  const [radialOpen, setRadialOpen] = useState(false);

  useEffect(() => {
    const handleKeyDown = (e: KeyboardEvent) => {
      // Cmd/Ctrl + Shift + R or some other shortcut to open Radial
      if ((e.metaKey || e.ctrlKey) && e.key === 'e') {
        e.preventDefault();
        setRadialOpen(prev => !prev);
      }
    };
    
    window.addEventListener('keydown', handleKeyDown);
    return () => window.removeEventListener('keydown', handleKeyDown);
  }, []);

  return (
    <>
      <CommandPalette />
      <RadialPalette isOpen={radialOpen} onClose={() => setRadialOpen(false)} />
      <Header />
      <PanelLayout
        leftPanel={<LeftPanel />}
        rightPanel={<RightPanel />}
        bottomPanel={<BottomPanel />}
      >
        <CenterContent />
      </PanelLayout>
      <StatusBar />
    </>
  );
}
