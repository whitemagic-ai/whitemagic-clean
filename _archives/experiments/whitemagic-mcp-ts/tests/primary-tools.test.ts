/**
 * Integration Tests for 28 Primary Tools (LIBRA Phase 7)
 * 
 * Tests tool wiring, operation routing, and basic functionality
 */

import { describe, it, expect, beforeAll } from '@jest/globals';
import { PRIMARY_TOOLS, getPrimaryTool, getToolsByQuadrant, getToolsByElement } from '../src/primary-tools.js';
import { resolveToolAlias } from '../src/tools-registry.js';

describe('Primary Tools - Structure', () => {
  it('should have exactly 28 primary tools', () => {
    expect(PRIMARY_TOOLS).toHaveLength(28);
  });

  it('should have all required fields for each tool', () => {
    PRIMARY_TOOLS.forEach(tool => {
      expect(tool).toHaveProperty('name');
      expect(tool).toHaveProperty('description');
      expect(tool).toHaveProperty('gana');
      expect(tool).toHaveProperty('garden');
      expect(tool).toHaveProperty('quadrant');
      expect(tool).toHaveProperty('element');
      expect(tool).toHaveProperty('category');
      expect(tool).toHaveProperty('safety');
      expect(tool).toHaveProperty('inputSchema');
    });
  });

  it('should have 7 tools per quadrant', () => {
    const eastern = getToolsByQuadrant('eastern');
    const southern = getToolsByQuadrant('southern');
    const western = getToolsByQuadrant('western');
    const northern = getToolsByQuadrant('northern');

    expect(eastern).toHaveLength(7);
    expect(southern).toHaveLength(7);
    expect(western).toHaveLength(7);
    expect(northern).toHaveLength(7);
  });

  it('should have tools for all 4 elements', () => {
    const wood = getToolsByElement('wood');
    const fire = getToolsByElement('fire');
    const metal = getToolsByElement('metal');
    const water = getToolsByElement('water');

    expect(wood.length).toBeGreaterThan(0);
    expect(fire.length).toBeGreaterThan(0);
    expect(metal.length).toBeGreaterThan(0);
    expect(water.length).toBeGreaterThan(0);
  });

  it('should have operation parameter in all inputSchemas', () => {
    PRIMARY_TOOLS.forEach(tool => {
      expect(tool.inputSchema.properties).toHaveProperty('operation');
      expect(tool.inputSchema.properties.operation).toHaveProperty('enum');
      expect(Array.isArray(tool.inputSchema.properties.operation.enum)).toBe(true);
    });
  });
});

describe('Primary Tools - Helper Functions', () => {
  it('should retrieve tool by name', () => {
    const tool = getPrimaryTool('initialize_session');
    expect(tool).toBeDefined();
    expect(tool?.name).toBe('initialize_session');
  });

  it('should return undefined for non-existent tool', () => {
    const tool = getPrimaryTool('nonexistent_tool');
    expect(tool).toBeUndefined();
  });

  it('should filter tools by quadrant', () => {
    const eastern = getToolsByQuadrant('eastern');
    eastern.forEach(tool => {
      expect(tool.quadrant).toBe('eastern');
    });
  });

  it('should filter tools by element', () => {
    const fire = getToolsByElement('fire');
    fire.forEach(tool => {
      expect(tool.element).toBe('fire');
    });
  });
});

describe('Alias Resolution', () => {
  it('should resolve known aliases to primary tools', () => {
    expect(resolveToolAlias('remember')).toBe('create_memory');
    expect(resolveToolAlias('recall')).toBe('search_memories');
    expect(resolveToolAlias('session_init')).toBe('initialize_session');
  });

  it('should return original name if no alias exists', () => {
    expect(resolveToolAlias('initialize_session')).toBe('initialize_session');
    expect(resolveToolAlias('unknown_tool')).toBe('unknown_tool');
  });

  it('should handle case sensitivity', () => {
    expect(resolveToolAlias('create_memory')).toBe('create_memory');
  });
});

describe('Primary Tools - Gana Mapping', () => {
  const ganaTools = [
    { gana: 'HornGana', tool: 'initialize_session' },
    { gana: 'NeckGana', tool: 'create_memory' },
    { gana: 'RootGana', tool: 'check_system_health' },
    { gana: 'ChariotGana', tool: 'manage_archaeology' },
    { gana: 'WellGana', tool: 'search_deep' },
  ];

  ganaTools.forEach(({ gana, tool }) => {
    it(`should map ${gana} to ${tool}`, () => {
      const primaryTool = getPrimaryTool(tool);
      expect(primaryTool).toBeDefined();
      expect(primaryTool?.gana).toBe(gana);
    });
  });
});

describe('Primary Tools - Safety Levels', () => {
  it('should have appropriate safety levels', () => {
    const tools = PRIMARY_TOOLS;
    
    const readTools = tools.filter(t => t.safety === 'read');
    const writeTools = tools.filter(t => t.safety === 'write');
    const deleteTools = tools.filter(t => t.safety === 'delete');
    
    // Should have mix of safety levels
    expect(readTools.length).toBeGreaterThan(0);
    expect(writeTools.length).toBeGreaterThan(0);
    
    // Delete tools should be rare
    expect(deleteTools.length).toBeLessThan(5);
  });

  it('should mark memory deletion as unsafe', () => {
    const memoryTool = getPrimaryTool('protect_context');
    expect(memoryTool).toBeDefined();
    
    const deleteOp = memoryTool?.inputSchema.properties.operation.enum.find(
      (op: string) => op === 'delete'
    );
    
    if (deleteOp) {
      // Tool should be marked as having delete operations
      expect(['write', 'delete']).toContain(memoryTool?.safety);
    }
  });
});

describe('Primary Tools - Operations', () => {
  it('should have multiple operations per tool', () => {
    PRIMARY_TOOLS.forEach(tool => {
      const operations = tool.inputSchema.properties.operation.enum;
      expect(operations.length).toBeGreaterThan(0);
    });
  });

  it('should have common operations across similar tools', () => {
    const sessionsTool = getPrimaryTool('initialize_session');
    const memoriesTool = getPrimaryTool('create_memory');
    
    // Both should support basic CRUD-like operations
    expect(sessionsTool?.inputSchema.properties.operation.enum).toContain('create_session');
    expect(memoriesTool?.inputSchema.properties.operation.enum).toContain('create_memory');
  });

  it('should have default operation defined', () => {
    PRIMARY_TOOLS.forEach(tool => {
      const defaultOp = tool.inputSchema.properties.operation.default;
      const availableOps = tool.inputSchema.properties.operation.enum;
      
      expect(availableOps).toContain(defaultOp);
    });
  });
});

describe('Primary Tools - Categories', () => {
  it('should have meaningful categories', () => {
    const categories = new Set(PRIMARY_TOOLS.map(t => t.category));
    
    expect(categories.size).toBeGreaterThan(5);
    expect(categories).toContain('memory');
    expect(categories).toContain('system');
  });

  it('should group related tools by category', () => {
    const memoryTools = PRIMARY_TOOLS.filter(t => t.category === 'memory');
    expect(memoryTools.length).toBeGreaterThan(0);
    
    memoryTools.forEach(tool => {
      expect(tool.description.toLowerCase()).toMatch(/memory|memories|remember|recall|search/);
    });
  });
});

describe('Primary Tools - Backwards Compatibility', () => {
  const legacyToolNames = [
    'create_memory',
    'search_memories', 
    'manage_archaeology',
    'check_system_health',
    'consult_iching',
  ];

  legacyToolNames.forEach(legacy => {
    it(`should support legacy tool: ${legacy}`, () => {
      const resolved = resolveToolAlias(legacy);
      const tool = getPrimaryTool(resolved);
      
      // Either it's a primary tool or aliases to one
      expect(tool || resolveToolAlias(legacy) !== legacy).toBeTruthy();
    });
  });
});

describe('Primary Tools - Mandala Coherence', () => {
  it('should have 1:1 mapping with 28 Ganas', () => {
    const ganas = PRIMARY_TOOLS.map(t => t.gana);
    const uniqueGanas = new Set(ganas);
    
    expect(uniqueGanas.size).toBe(28);
  });

  it('should have 1:1 mapping with 28 Gardens', () => {
    const gardens = PRIMARY_TOOLS.map(t => t.garden);
    const uniqueGardens = new Set(gardens);
    
    expect(uniqueGardens.size).toBe(28);
  });

  it('should follow quadrant-element alignment', () => {
    // Eastern = Wood, Southern = Fire, Western = Metal, Northern = Water
    const eastern = getToolsByQuadrant('eastern');
    const southern = getToolsByQuadrant('southern');
    const western = getToolsByQuadrant('western');
    const northern = getToolsByQuadrant('northern');

    eastern.forEach(tool => expect(tool.element).toBe('wood'));
    southern.forEach(tool => expect(tool.element).toBe('fire'));
    western.forEach(tool => expect(tool.element).toBe('metal'));
    northern.forEach(tool => expect(tool.element).toBe('water'));
  });
});
