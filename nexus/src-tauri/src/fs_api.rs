use std::fs;
use std::path::{Path, PathBuf};
use serde::{Serialize, Deserialize};

#[derive(Serialize, Deserialize)]
pub struct FileNode {
    name: String,
    path: String,
    #[serde(rename = "type")]
    node_type: String,
    children: Option<Vec<FileNode>>,
}

#[tauri::command]
pub fn list_directory(dir_path: String) -> Result<Vec<FileNode>, String> {
    let path = Path::new(&dir_path);
    if !path.exists() {
        return Err("Path does not exist".into());
    }

    let mut nodes = Vec::new();
    match fs::read_dir(path) {
        Ok(entries) => {
            for entry in entries {
                if let Ok(entry) = entry {
                    let file_type = entry.file_type().unwrap();
                    let name = entry.file_name().into_string().unwrap_or_default();
                    
                    // Skip hidden files/dirs like .git, node_modules, etc.
                    if name.starts_with('.') || name == "node_modules" || name == "target" || name == "__pycache__" {
                        continue;
                    }

                    let path_str = entry.path().to_string_lossy().into_owned();
                    
                    if file_type.is_dir() {
                        // Recursively get children but limit depth or just do 1 level and lazy load
                        nodes.push(FileNode {
                            name,
                            path: path_str,
                            node_type: "folder".into(),
                            children: Some(Vec::new()), // Could populate, but lazy is better
                        });
                    } else {
                        nodes.push(FileNode {
                            name,
                            path: path_str,
                            node_type: "file".into(),
                            children: None,
                        });
                    }
                }
            }
        }
        Err(e) => return Err(e.to_string()),
    }
    
    // Sort: folders first, then files
    nodes.sort_by(|a, b| {
        if a.node_type == b.node_type {
            a.name.cmp(&b.name)
        } else if a.node_type == "folder" {
            std::cmp::Ordering::Less
        } else {
            std::cmp::Ordering::Greater
        }
    });

    Ok(nodes)
}

#[tauri::command]
pub fn read_file(file_path: String) -> Result<String, String> {
    fs::read_to_string(&file_path).map_err(|e| e.to_string())
}

#[tauri::command]
pub fn write_file(file_path: String, content: String) -> Result<(), String> {
    fs::write(&file_path, content).map_err(|e| e.to_string())
}
