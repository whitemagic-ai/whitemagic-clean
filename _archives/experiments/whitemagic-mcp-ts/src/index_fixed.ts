// Quick fix: Wrap responses to satisfy MCP SDK type requirements
import { ReadResourceRequestSchema, CallToolRequestSchema } from '@modelcontextprotocol/sdk/types.js';

// Helper to wrap responses with proper ServerResult type
function wrapResponse<T>(content: T): any {
  return {
    contents: Array.isArray(content) ? content : [content],
    _meta: {}
  };
}

// Apply to line 212 and 327 handlers
