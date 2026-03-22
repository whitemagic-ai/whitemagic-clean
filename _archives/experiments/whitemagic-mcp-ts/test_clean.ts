import { PRIMARY_TOOLS } from './src/primary-tools.js';

/**
 * Clean schema for Gemini compatibility
 * - Removes problematic keywords: default, additionalProperties, title, examples, const, $schema, pattern, format
 * - Converts numeric enums to strings
 * - Strips all non-ASCII characters from descriptions
 * - Truncates descriptions to 100 characters
 * - CRITICAL: Simplifies ALL nested structures to strings to avoid Gemini parser crashes
 * - Synchronizes 'required' array with actual properties
 */
function cleanSchemaForGemini(schema: any, depth = 0): any {
  if (!schema || typeof schema !== 'object') return schema;

  // Root or properties objects should stay as they are
  const clean: any = {};
  const skipKeywords = ['default', 'additionalProperties', 'title', 'examples', 'const', '$schema', 'pattern', 'format'];
  
  for (const [key, value] of Object.entries(schema)) {
    // Skip problematic keywords
    if (skipKeywords.includes(key)) continue;

    if (key === 'description' && typeof value === 'string') {
      // Strip emojis and non-ASCII, then truncate
      let desc = value.replace(/[^\x00-\x7F]/g, '').trim();
      if (desc.length > 100) desc = desc.substring(0, 97) + '...';
      clean[key] = desc;
      continue;
    }

    if (key === 'enum' && Array.isArray(value)) {
      // Enums must stay as arrays of strings
      clean[key] = value
        .filter(v => v !== null)
        .map(v => String(v));
      continue;
    }

    if (key === 'required' && Array.isArray(value)) {
      // Required must stay as array of strings
      clean[key] = value.filter(v => typeof v === 'string');
      continue;
    }

    if (key === 'properties' && typeof value === 'object' && value !== null) {
      const cleanProps: any = {};
      for (const [propName, propValue] of Object.entries(value)) {
        // Deep properties (depth >= 1) that are objects should be simplified to strings
        if (typeof propValue === 'object' && propValue !== null && (propValue as any).type === 'object') {
          cleanProps[propName] = {
            type: 'string',
            description: `${(propValue as any).description || 'Object data'}. Pass as JSON string.`
          };
        } else if (typeof propValue === 'object' && propValue !== null && (propValue as any).type === 'array') {
          // Simplify complex arrays too
          const items = (propValue as any).items;
          if (items && typeof items === 'object' && items.type === 'object') {
            cleanProps[propName] = {
              type: 'string',
              description: `${(propValue as any).description || 'List of objects'}. Pass as JSON string.`
            };
          } else {
            cleanProps[propName] = cleanSchemaForGemini(propValue, depth + 1);
          }
        } else {
          cleanProps[propName] = cleanSchemaForGemini(propValue, depth + 1);
        }
      }
      clean[key] = cleanProps;
      continue;
    }

    if (typeof value === 'object' && value !== null) {
      // Handle items or other nested structures
      if (key === 'items') {
        if ((value as any).type === 'object') {
          clean[key] = {
            type: 'string',
            description: 'Object data (JSON)'
          };
        } else {
          clean[key] = cleanSchemaForGemini(value, depth + 1);
        }
      }
    } else {
      // Prefer 'number' over 'integer'
      if (key === 'type' && value === 'integer') {
        clean[key] = 'number';
      } else {
        clean[key] = value;
      }
    }
  }

  // Final Pass Sanitization
  
  // 1. Handle object types at root
  if (depth === 0 && clean.type === 'object') {
    if (!clean.properties || Object.keys(clean.properties).length === 0) {
      clean.properties = {
        _info: { type: 'string', description: 'Placeholder for object data' }
      };
    }
  }

  // 2. Synchronize 'required' array
  if (clean.required && Array.isArray(clean.required)) {
    const props = clean.properties ? Object.keys(clean.properties) : [];
    clean.required = clean.required.filter((r: string) => props.includes(r));
    if (clean.required.length === 0) delete clean.required;
  }

  return clean;
}

const tools = PRIMARY_TOOLS.map(t => ({
  name: t.name.replace(/[^\x00-\x7F]/g, ''),
  description: t.description.replace(/[^\x00-\x7F]/g, '').substring(0, 100).trim(),
  inputSchema: cleanSchemaForGemini(t.inputSchema)
}));

console.log(JSON.stringify(tools, null, 2));
