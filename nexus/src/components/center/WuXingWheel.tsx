import { useEffect, useRef } from 'react';
import * as d3 from 'd3';

interface WuXingWheelProps {
  currentPhase: 'WOOD' | 'FIRE' | 'EARTH' | 'METAL' | 'WATER';
}

const phases = [
  { name: 'WOOD', label: '木 Planning', color: '#10b981', angle: 0 },
  { name: 'FIRE', label: '火 Execution', color: '#ef4444', angle: 72 },
  { name: 'EARTH', label: '土 Testing', color: '#f59e0b', angle: 144 },
  { name: 'METAL', label: '金 Refinement', color: '#6b7280', angle: 216 },
  { name: 'WATER', label: '水 Reflection', color: '#3b82f6', angle: 288 },
];

export default function WuXingWheel({ currentPhase }: WuXingWheelProps) {
  const svgRef = useRef<SVGSVGElement>(null);

  useEffect(() => {
    if (!svgRef.current) return;

    const width = 300;
    const height = 300;
    const radius = Math.min(width, height) / 2 - 40;
    const centerX = width / 2;
    const centerY = height / 2;

    d3.select(svgRef.current).selectAll('*').remove();

    const svg = d3.select(svgRef.current)
      .attr('width', width)
      .attr('height', height);

    const g = svg.append('g')
      .attr('transform', `translate(${centerX},${centerY})`);

    const arc = d3.arc<any>()
      .innerRadius(radius - 20)
      .outerRadius(radius)
      .startAngle((d) => (d.angle * Math.PI) / 180)
      .endAngle((d) => ((d.angle + 72) * Math.PI) / 180);

    // Draw phase segments
    g.selectAll('path')
      .data(phases)
      .enter()
      .append('path')
      .attr('d', arc)
      .attr('fill', (d) => d.color)
      .attr('opacity', (d) => (d.name === currentPhase ? 1 : 0.2))
      .attr('stroke', '#1e1e2e')
      .attr('stroke-width', 2)
      .style('transition', 'opacity 0.5s ease');

    // Add labels
    g.selectAll('text')
      .data(phases)
      .enter()
      .append('text')
      .attr('transform', (d) => {
        const angle = (d.angle + 36) * Math.PI / 180;
        return `translate(${Math.sin(angle) * (radius + 20)}, ${-Math.cos(angle) * (radius + 20)})`;
      })
      .attr('dy', '0.35em')
      .attr('text-anchor', 'middle')
      .attr('fill', (d) => (d.name === currentPhase ? '#fff' : '#6b7280'))
      .style('font-size', '12px')
      .style('font-family', 'monospace')
      .text((d) => d.label)
      .style('transition', 'fill 0.5s ease');

    // Add generating cycle arrows (inner)
    const arrowRadius = radius - 30;
    g.append('circle')
      .attr('r', arrowRadius)
      .attr('fill', 'none')
      .attr('stroke', '#3b3b4f')
      .attr('stroke-width', 1)
      .attr('stroke-dasharray', '4,4');

    // Center icon
    g.append('text')
      .attr('text-anchor', 'middle')
      .attr('dy', '0.1em')
      .attr('fill', '#a855f7')
      .style('font-size', '24px')
      .text('☯');

  }, [currentPhase]);

  return (
    <div className="flex flex-col items-center justify-center p-4 bg-wm-bg-panel border border-wm-border rounded-xl">
      <h3 className="text-sm font-semibold text-gray-300 mb-2">Wu Xing System Phase</h3>
      <svg ref={svgRef} className="max-w-full h-auto drop-shadow-xl" />
      <div className="mt-4 text-xs text-gray-400 text-center">
        Current operating mode: <span className="text-wm-purple-400 font-mono">{currentPhase}</span>
      </div>
    </div>
  );
}
