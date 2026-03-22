import { Tool } from '@modelcontextprotocol/sdk/types.js';
import { execSync } from 'child_process';
import * as path from 'path';
import * as fs from 'fs/promises';
import * as os from 'os';

export const windsurfBackupTool: Tool = {
  name: 'windsurf_backup',
  description: 'Backup Windsurf conversations for transfer between machines',
  inputSchema: {
    type: 'object',
    properties: {
      destination: {
        type: 'string',
        description: 'Destination directory for backup (optional, defaults to windsurf_conversations_archive)',
        default: 'windsurf_conversations_archive'
      },
      compress: {
        type: 'boolean',
        description: 'Whether to compress the backup into a tar.gz file',
        default: false
      }
    }
  }
};

export async function handleWindsurfBackup(args: any) {
  const { destination = 'windsurf_conversations_archive', compress = false } = args;
  const projectRoot = process.cwd();
  const timestamp = new Date().toISOString().replace(/[:.]/g, '-').slice(0, 19);
  const backupName = `backup_${timestamp}`;
  const backupPath = path.join(projectRoot, destination, backupName);
  
  try {
    // Create archive directory
    await fs.mkdir(path.dirname(backupPath), { recursive: true });
    
    // Check if Windsurf exists
    const cascadeDir = path.join(os.homedir(), '.codeium/windsurf/cascade');
    try {
      await fs.access(cascadeDir);
    } catch {
      return {
        success: false,
        error: 'Windsurf cascade directory not found. Please ensure Windsurf is installed and has been used.'
      };
    }
    
    // Count conversation files
    const pbFiles = await fs.readdir(cascadeDir);
    const conversationCount = pbFiles.filter(f => f.endsWith('.pb')).length;
    
    if (conversationCount === 0) {
      return {
        success: false,
        warning: 'No conversation files found. Have you had any conversations in Windsurf yet?'
      };
    }
    
    // Run the Python backup script
    const scriptPath = path.join(projectRoot, 'scripts', 'backup_windsurf_conversations.py');
    try {
      execSync(`python3 "${scriptPath}" "${backupPath}"`, { stdio: 'pipe' });
    } catch (error: any) {
      return {
        success: false,
        error: `Backup script failed: ${error.message}`
      };
    }
    
    // Create summary
    const summary = {
      backupDate: new Date().toISOString(),
      backupName,
      location: backupPath,
      conversationCount,
      configFiles: 0
    };
    
    const configDir = path.join(backupPath, 'config');
    try {
      const configs = await fs.readdir(configDir);
      summary.configFiles = configs.length;
    } catch {}
    
    await fs.writeFile(
      path.join(backupPath, 'backup_summary.json'),
      JSON.stringify(summary, null, 2)
    );
    
    // Compress if requested
    let compressedPath = null;
    if (compress) {
      try {
        const archiveDir = path.dirname(backupPath);
        execSync(`cd "${archiveDir}" && tar -czf "${backupName}.tar.gz" "${backupName}"`, { stdio: 'pipe' });
        compressedPath = path.join(archiveDir, `${backupName}.tar.gz`);
      } catch (error: any) {
        console.warn('Compression failed:', error.message);
      }
    }
    
    return {
      success: true,
      data: {
        backupPath,
        compressedPath,
        conversationCount,
        configFiles: summary.configFiles,
        instructions: [
          'To transfer to another machine:',
          `1. Copy the ${compressedPath ? 'compressed .tar.gz file' : 'backup folder'}`,
          '2. On the target machine, run: python3 restore_conversations.py .',
          '3. Restart Windsurf'
        ]
      }
    };
  } catch (error: any) {
    return {
      success: false,
      error: error.message
    };
  }
}

export const windsurfRestoreTool: Tool = {
  name: 'windsurf_restore',
  description: 'Restore Windsurf conversations from a backup',
  inputSchema: {
    type: 'object',
    properties: {
      backupPath: {
        type: 'string',
        description: 'Path to the backup directory or .tar.gz file',
        required: true
      }
    }
  }
};

export async function handleWindsurfRestore(args: any) {
  const { backupPath } = args;
  
  try {
    // Check if backup exists
    const stats = await fs.stat(backupPath);
    
    let restoreDir = backupPath;
    
    // If it's a compressed file, extract it first
    if (backupPath.endsWith('.tar.gz')) {
      const extractDir = path.join(path.dirname(backupPath), path.basename(backupPath, '.tar.gz'));
      try {
        execSync(`tar -xzf "${backupPath}" -C "${path.dirname(backupPath)}"`, { stdio: 'pipe' });
        restoreDir = extractDir;
      } catch (error: any) {
        return {
          success: false,
          error: `Failed to extract backup: ${error.message}`
        };
      }
    }
    
    // Check if restore script exists
    const restoreScript = path.join(restoreDir, 'restore_conversations.py');
    try {
      await fs.access(restoreScript);
    } catch {
      return {
        success: false,
        error: 'Restore script not found in backup. Is this a valid Windsurf backup?'
      };
    }
    
    // Run the restore script
    try {
      execSync(`cd "${restoreDir}" && python3 restore_conversations.py .`, { stdio: 'pipe' });
    } catch (error: any) {
      return {
        success: false,
        error: `Restore script failed: ${error.message}`
      };
    }
    
    return {
      success: true,
      data: {
        message: 'Restore completed successfully!',
        instructions: [
          'Please restart Windsurf to see the imported conversations.',
          'If Windsurf was already running, you may need to restart it completely.'
        ]
      }
    };
  } catch (error: any) {
    return {
      success: false,
      error: error.message
    };
  }
}

export const windsurfMergeTool: Tool = {
  name: 'windsurf_merge_backups',
  description: 'Merge multiple Windsurf backups into one unified backup',
  inputSchema: {
    type: 'object',
    properties: {
      backupPaths: {
        type: 'array',
        items: { type: 'string' },
        description: 'Array of backup directory paths to merge',
        required: true
      },
      outputName: {
        type: 'string',
        description: 'Name for the merged backup (optional)',
        default: null
      }
    }
  }
};

export async function handleWindsurfMerge(args: any) {
  const { backupPaths, outputName } = args;
  const projectRoot = process.cwd();
  const timestamp = new Date().toISOString().replace(/[:.]/g, '-').slice(0, 19);
  const mergedName = outputName || `merged_backup_${timestamp}`;
  const mergedPath = path.join(projectRoot, 'windsurf_conversations_archive', mergedName);
  
  try {
    // Verify all backups exist
    for (const backupPath of backupPaths) {
      try {
        await fs.access(backupPath);
      } catch {
        return {
          success: false,
          error: `Backup not found: ${backupPath}`
        };
      }
    }
    
    // Run the merge script
    const scriptPath = path.join(projectRoot, 'scripts', 'merge_windsurf_backups.py');
    const cmd = `python3 "${scriptPath}" ${backupPaths.map((p: string) => `"${p}"`).join(' ')} "${mergedPath}"`;
    
    try {
      execSync(cmd, { stdio: 'pipe' });
    } catch (error: any) {
      return {
        success: false,
        error: `Merge failed: ${error.message}`
      };
    }
    
    return {
      success: true,
      data: {
        mergedPath,
        sourceBackups: backupPaths.length,
        instructions: [
          'To restore the merged backup:',
          '1. Copy the merged backup folder to the target machine',
          '2. Run: python3 restore_merged_conversations.py .',
          '3. Restart Windsurf'
        ]
      }
    };
  } catch (error: any) {
    return {
      success: false,
      error: error.message
    };
  }
}
