/**
 * WhiteMagic MCP Extension Resources
 * New resources for v4.6.0
 */

import { readFileSync } from 'fs';
import { join } from 'path';

interface Resource {
  uri: string;
  name: string;
  description: string;
  mimeType: string;
}

interface ResourceContents {
  contents: Array<{
    uri: string;
    mimeType: string;
    text: string;
  }>;
}

/**
 * Get list of available extension resources
 */
export function getExtensionResources(): Resource[] {
  return [
    {
      uri: "grimoire://chapter/1",
      name: "Grimoire Chapter 1: Introduction",
      description: "Introduction to WhiteMagic philosophy and architecture",
      mimeType: "text/markdown"
    },
    {
      uri: "grimoire://chapter/24",
      name: "Grimoire Chapter 24: AI Onboarding",
      description: "Guide for AI agents working with WhiteMagic",
      mimeType: "text/markdown"
    },
    {
      uri: "grimoire://chapter/25",
      name: "Grimoire Chapter 25: Extension System",
      description: "How to use and create WhiteMagic extensions",
      mimeType: "text/markdown"
    },
    {
      uri: "matrix://system/core",
      name: "System Architecture: Core",
      description: "Core WhiteMagic system architecture",
      mimeType: "text/markdown"
    },
    {
      uri: "matrix://system/extensions",
      name: "System Architecture: Extensions",
      description: "Extension system architecture and module structure",
      mimeType: "text/markdown"
    },
    {
      uri: "gardens://list",
      name: "Gardens Directory",
      description: "List of all 14 consciousness domains",
      mimeType: "application/json"
    },
    {
      uri: "gardens://garden/joy",
      name: "Joy Garden",
      description: "Documentation for the Joy garden",
      mimeType: "text/markdown"
    },
    {
      uri: "gardens://garden/wisdom",
      name: "Wisdom Garden",
      description: "Documentation for the Wisdom garden",
      mimeType: "text/markdown"
    },
    {
      uri: "metrics://wuxing",
      name: "Wu Xing Metrics",
      description: "Five Elements balance metrics",
      mimeType: "application/json"
    },
    {
      uri: "state://coherence",
      name: "Coherence State",
      description: "Current AI coherence level and iteration count",
      mimeType: "application/json"
    },
    {
      uri: "state://immune",
      name: "Immune System Status",
      description: "Current immune system health and threat level",
      mimeType: "application/json"
    }
  ];
}

/**
 * Read resource contents
 */
export async function readExtensionResource(uri: string): Promise<ResourceContents> {
  const [protocol, path] = uri.split("://");
  
  switch (protocol) {
    case "grimoire":
      return readGrimoireChapter(path);
    case "matrix":
      return readMatrixDoc(path);
    case "gardens":
      return readGardenDoc(path);
    case "metrics":
      return readMetrics(path);
    case "state":
      return readState(path);
    default:
      throw new Error(`Unknown protocol: ${protocol}`);
  }
}

async function readGrimoireChapter(path: string): Promise<ResourceContents> {
  const chapterMatch = path.match(/chapter\/(\d+)/);
  if (!chapterMatch) {
    throw new Error(`Invalid grimoire path: ${path}`);
  }
  
  const chapterNum = chapterMatch[1];
  const grimoirePath = join(process.cwd(), '../grimoire', `chapter_${chapterNum}.md`);
  
  try {
    const content = readFileSync(grimoirePath, 'utf-8');
    return {
      contents: [{
        uri: `grimoire://${path}`,
        mimeType: "text/markdown",
        text: content
      }]
    };
  } catch (error) {
    // Return placeholder if file doesn't exist
    return {
      contents: [{
        uri: `grimoire://${path}`,
        mimeType: "text/markdown",
        text: `# Chapter ${chapterNum}\n\n*Content coming soon*`
      }]
    };
  }
}

async function readMatrixDoc(path: string): Promise<ResourceContents> {
  const docs: Record<string, string> = {
    "system/core": `# Core System Architecture

## Components
- **core/memory**: Unified memory management
- **core/resonance**: Gan Ying event bus
- **core/orchestration**: System bootstrap
- **core/config**: Configuration management

## Storage Tiers
- Short-term: Active working memory
- Long-term: Consolidated knowledge
- Archive: Historical records

## API Layer
- REST API via FastAPI
- WebSocket support for real-time events
- Authentication & authorization
`,
    "system/extensions": `# Extension System Architecture

## Extension Types
1. **Gardens** - Consciousness domains
2. **Intelligence** - Agentic AI systems
3. **Systems** - Automation & monitoring
4. **Symbolic** - I Ching, Wu Xing
5. **Edge** - Thought clones
6. **Autonomous** - Parallel cognition

## Installation
\`\`\`bash
# Individual extensions
pip install whitemagic-gardens
pip install whitemagic-intelligence

# All extensions
pip install whitemagic[all]
\`\`\`

## Discovery
Extensions register via entry points and are auto-discovered by core.
`
  };
  
  const content = docs[path] || `# ${path}\n\n*Documentation coming soon*`;
  
  return {
    contents: [{
      uri: `matrix://${path}`,
      mimeType: "text/markdown",
      text: content
    }]
  };
}

async function readGardenDoc(path: string): Promise<ResourceContents> {
  if (path === "list") {
    const gardens = {
      gardens: [
        { name: "beauty", description: "Aesthetic appreciation and harmony" },
        { name: "connection", description: "Relationships and bonds" },
        { name: "dharma", description: "Righteous action and ethics" },
        { name: "joy", description: "Happiness and delight" },
        { name: "love", description: "Compassion and care" },
        { name: "mystery", description: "Wonder and the unknown" },
        { name: "play", description: "Experimentation and fun" },
        { name: "practice", description: "Discipline and skill development" },
        { name: "presence", description: "Mindfulness and awareness" },
        { name: "sangha", description: "Community and mutual support" },
        { name: "truth", description: "Honesty and authenticity" },
        { name: "voice", description: "Expression and communication" },
        { name: "wisdom", description: "Knowledge and insight" },
        { name: "wonder", description: "Curiosity and awe" }
      ],
      total: 14,
      version: "4.6.0"
    };
    
    return {
      contents: [{
        uri: "gardens://list",
        mimeType: "application/json",
        text: JSON.stringify(gardens, null, 2)
      }]
    };
  }
  
  const gardenMatch = path.match(/garden\/(\w+)/);
  if (!gardenMatch) {
    throw new Error(`Invalid garden path: ${path}`);
  }
  
  const gardenName = gardenMatch[1];
  
  return {
    contents: [{
      uri: `gardens://${path}`,
      mimeType: "text/markdown",
      text: `# ${gardenName.charAt(0).toUpperCase() + gardenName.slice(1)} Garden\n\n*Documentation coming soon*\n\nInstall with: \`pip install whitemagic-gardens\`\n`
    }]
  };
}

async function readMetrics(path: string): Promise<ResourceContents> {
  if (path === "wuxing") {
    const metrics = {
      elements: {
        wood: { value: 0.8, description: "Growth and expansion" },
        fire: { value: 0.6, description: "Transformation and passion" },
        earth: { value: 0.9, description: "Stability and nourishment" },
        metal: { value: 0.7, description: "Structure and refinement" },
        water: { value: 0.5, description: "Flow and wisdom" }
      },
      balance: "Good",
      recommendations: [
        "Increase Water element through reflection",
        "Maintain Earth element stability"
      ],
      timestamp: new Date().toISOString()
    };
    
    return {
      contents: [{
        uri: "metrics://wuxing",
        mimeType: "application/json",
        text: JSON.stringify(metrics, null, 2)
      }]
    };
  }
  
  throw new Error(`Unknown metrics path: ${path}`);
}

async function readState(path: string): Promise<ResourceContents> {
  if (path === "coherence") {
    const state = {
      level: 85,
      iteration: 1,
      callsThisHour: 0,
      maxCallsPerHour: 100,
      status: "optimal",
      timestamp: new Date().toISOString()
    };
    
    return {
      contents: [{
        uri: "state://coherence",
        mimeType: "application/json",
        text: JSON.stringify(state, null, 2)
      }]
    };
  }
  
  if (path === "immune") {
    const state = {
      health: "healthy",
      threatLevel: "low",
      lastScan: new Date().toISOString(),
      threatsDetected: 0,
      autoHealEnabled: true
    };
    
    return {
      contents: [{
        uri: "state://immune",
        mimeType: "application/json",
        text: JSON.stringify(state, null, 2)
      }]
    };
  }
  
  throw new Error(`Unknown state path: ${path}`);
}
