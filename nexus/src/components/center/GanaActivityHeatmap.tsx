import { useEffect, useRef, useState } from 'react';
import * as d3 from 'd3';
import { Activity } from 'lucide-react';

interface GanaActivity {
  mansion: string;
  quadrant: 'east' | 'south' | 'west' | 'north';
  invocations: number;
  avgExecutionMs: number;
  lastActive: string;
}

export default function GanaActivityHeatmap() {
  const svgRef = useRef<SVGSVGElement>(null);
  const [ganaData, setGanaData] = useState<GanaActivity[]>([]);
  const [selectedGana, setSelectedGana] = useState<GanaActivity | null>(null);

  useEffect(() => {
    setGanaData(mockGanaData());
    const interval = setInterval(() => setGanaData(mockGanaData()), 5000);
    return () => clearInterval(interval);
  }, []);

  useEffect(() => {
    if (!svgRef.current || ganaData.length === 0) return;

    const svg = d3.select(svgRef.current);
    svg.selectAll('*').remove();

    // Use responsive container size
    const width = 300;
    const height = 300;
    const centerX = width / 2;
    const centerY = height / 2;
    const radius = Math.min(width, height) / 2 - 20;

    const ganas = ganaData;
    const angleStep = (2 * Math.PI) / 28;

    const colorScale = d3.scaleSequential(d3.interpolatePurples)
      .domain([0, d3.max(ganas, d => d.invocations) || 100]);

    svg.append('circle')
      .attr('cx', centerX)
      .attr('cy', centerY)
      .attr('r', radius)
      .attr('fill', 'none')
      .attr('stroke', '#1e1e2e')
      .attr('stroke-width', 2);

    svg.append('line')
      .attr('x1', centerX)
      .attr('y1', centerY - radius)
      .attr('x2', centerX)
      .attr('y2', centerY + radius)
      .attr('stroke', '#3b3b4f')
      .attr('stroke-width', 1)
      .attr('stroke-dasharray', '4,4');

    svg.append('line')
      .attr('x1', centerX - radius)
      .attr('y1', centerY)
      .attr('x2', centerX + radius)
      .attr('y2', centerY)
      .attr('stroke', '#3b3b4f')
      .attr('stroke-width', 1)
      .attr('stroke-dasharray', '4,4');

    const arc = d3.arc<any>()
      .innerRadius(radius - 30)
      .outerRadius(radius)
      .startAngle((_d, i) => i * angleStep)
      .endAngle((_d, i) => (i + 1) * angleStep)
      .padAngle(0.02)
      .padRadius(radius);

    const g = svg.append('g').attr('transform', `translate(${centerX},${centerY})`);

    g.selectAll('path')
      .data(ganas)
      .enter()
      .append('path')
      .attr('d', arc)
      .attr('fill', d => colorScale(d.invocations))
      .attr('stroke', '#0a0a0f')
      .attr('stroke-width', 1)
      .style('cursor', 'pointer')
      .style('transition', 'fill 0.3s ease')
      .on('mouseenter', (event, d) => {
        d3.select(event.currentTarget)
          .attr('stroke', '#a855f7')
          .attr('stroke-width', 2);
        setSelectedGana(d);
      })
      .on('mouseleave', (event) => {
        d3.select(event.currentTarget)
          .attr('stroke', '#0a0a0f')
          .attr('stroke-width', 1);
        setSelectedGana(null);
      });

    // Add quadrant labels
    const qLabels = [
      { text: 'E', angle: -Math.PI / 4, color: '#10b981' }, // Wood
      { text: 'S', angle: Math.PI / 4, color: '#ef4444' },  // Fire
      { text: 'W', angle: 3 * Math.PI / 4, color: '#6b7280' }, // Metal
      { text: 'N', angle: 5 * Math.PI / 4, color: '#3b82f6' }  // Water
    ];

    g.selectAll('text')
      .data(qLabels)
      .enter()
      .append('text')
      .attr('transform', d => `translate(${Math.sin(d.angle) * (radius - 50)}, ${-Math.cos(d.angle) * (radius - 50)})`)
      .attr('text-anchor', 'middle')
      .attr('dy', '0.35em')
      .attr('fill', d => d.color)
      .style('font-size', '12px')
      .style('font-weight', 'bold')
      .style('opacity', 0.5)
      .text(d => d.text);

  }, [ganaData]);

  return (
    <div className="flex flex-col items-center justify-center p-4 bg-wm-bg-panel border border-wm-border rounded-xl h-full">
      <div className="flex w-full justify-between items-start mb-2">
        <h3 className="text-sm font-semibold text-gray-300 flex items-center gap-2">
          <Activity size={16} className="text-wm-purple-400" />
          28 Gana Network
        </h3>
      </div>
      
      <div className="relative flex-1 flex items-center justify-center w-full min-h-[200px]">
        <svg ref={svgRef} className="w-full max-w-[300px] h-auto drop-shadow-xl" viewBox="0 0 300 300" preserveAspectRatio="xMidYMid meet" />
        
        {/* Center content */}
        <div className="absolute inset-0 flex items-center justify-center pointer-events-none">
          {selectedGana ? (
            <div className="flex flex-col items-center justify-center bg-wm-bg/80 backdrop-blur rounded-full w-[80px] h-[80px] border border-wm-purple-500/30">
              <span className="text-[10px] text-gray-400 uppercase">{selectedGana.quadrant}</span>
              <span className="text-xs font-bold text-white text-center leading-tight truncate px-2 w-full">{selectedGana.mansion}</span>
              <span className="text-[10px] text-wm-purple-300">{selectedGana.invocations} ops</span>
            </div>
          ) : (
            <div className="w-4 h-4 rounded-full bg-wm-purple-500/20 border border-wm-purple-500/50 animate-pulse" />
          )}
        </div>
      </div>
    </div>
  );
}

function mockGanaData(): GanaActivity[] {
  const mansions = [
    'Horn', 'Neck', 'Root', 'Room', 'Heart', 'Tail', 'Winnow Basket',
    'Dipper', 'Ox', 'Woman', 'Void', 'Rooftop', 'Encampment', 'Wall',
    'Legs', 'Bond', 'Stomach', 'Hairy Head', 'Net', 'Turtle Beak', 'Three Stars',
    'Well', 'Ghost', 'Willow', 'Star', 'Extended Net', 'Wings', 'Chariot'
  ];

  const quadrants: Array<'east' | 'south' | 'west' | 'north'> = [
    ...(new Array(7).fill('east')),
    ...(new Array(7).fill('south')),
    ...(new Array(7).fill('west')),
    ...(new Array(7).fill('north'))
  ];

  return mansions.map((mansion, i) => ({
    mansion,
    quadrant: quadrants[i],
    // Create organic looking hot spots that drift over time
    invocations: Math.floor((Math.sin(Date.now() / 10000 + i) + 1) * 50) + Math.floor(Math.random() * 20),
    avgExecutionMs: Math.floor(Math.random() * 2000) + 100,
    lastActive: new Date().toISOString()
  }));
}
