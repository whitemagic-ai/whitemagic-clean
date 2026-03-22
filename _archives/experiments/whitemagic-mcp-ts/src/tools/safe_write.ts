/**
 * Safe File Write Tool for MCP
 * 
 * Eliminates Windsurf editor crashes through shell heredoc best practices.
 */

import { exec } from 'child_process';
import { promisify } from 'util';
import * as fs from 'fs/promises';
import * as path from 'path';

const execAsync = promisify(exec);

export interface SafeWriteParams {
  path: string;
  content: string;
  timeout_seconds?: number;
  verify?: boolean;
  create_backup?: boolean;
}

export interface SafeWriteResult {
  success: boolean;
  path: string;
  bytes_written: number;
  duration_ms: number;
  backup_path?: string;
  error?: string;
}

export async function safeWriteFile(params: SafeWriteParams): Promise<SafeWriteResult> {
  const startTime = Date.now();
  const timeout = params.timeout_seconds || 10;
  const absolutePath = path.resolve(params.path);
  
  try {
    const dir = path.dirname(absolutePath);
    await fs.mkdir(dir, { recursive: true });
    
    let backupPath: string | undefined;
    if (params.create_backup) {
      try {
        await fs.access(absolutePath);
        backupPath = `${absolutePath}.backup.${Date.now()}`;
        await fs.copyFile(absolutePath, backupPath);
      } catch {}
    }
    
    const command = `timeout ${timeout}s bash -c "cat > '${absolutePath}' << 'WHITEMAGIC_EOF'
${params.content}
WHITEMAGIC_EOF
"`;
    
    await execAsync(command, {
      maxBuffer: 50 * 1024 * 1024,
      timeout: timeout * 1000
    });
    
    if (params.verify) {
      const written = await fs.readFile(absolutePath, 'utf-8');
      if (written !== params.content) {
        throw new Error('Verification failed');
      }
    }
    
    const stats = await fs.stat(absolutePath);
    
    return {
      success: true,
      path: absolutePath,
      bytes_written: stats.size,
      duration_ms: Date.now() - startTime,
      backup_path: backupPath
    };
    
  } catch (error: any) {
    return {
      success: false,
      path: absolutePath,
      bytes_written: 0,
      duration_ms: Date.now() - startTime,
      error: error.message
    };
  }
}
