//! Galaxy Manager V2 - Enhanced Galaxy Management (PSR-001)
//! Target: 50× speedup for galaxy operations

use pyo3::prelude::*;
use std::collections::HashMap;
use std::sync::{Arc, RwLock};

#[derive(Clone, Debug)]
#[pyclass]
pub struct PyGalaxyManagerV2 {
    galaxies: Arc<RwLock<HashMap<String, GalaxyInfo>>>,
    active_galaxy: Arc<RwLock<Option<String>>>,
}

#[derive(Clone, Debug)]
struct GalaxyInfo {
    _name: String,
    memory_count: usize,
    created_at: f64,
    last_accessed: f64,
}

#[pymethods]
impl PyGalaxyManagerV2 {
    #[new]
    fn new() -> Self {
        Self {
            galaxies: Arc::new(RwLock::new(HashMap::new())),
            active_galaxy: Arc::new(RwLock::new(None)),
        }
    }

    fn create_galaxy(&mut self, name: String) -> PyResult<bool> {
        let mut galaxies = self.galaxies.write().unwrap();
        
        if galaxies.contains_key(&name) {
            return Ok(false);
        }
        
        let now = std::time::SystemTime::now()
            .duration_since(std::time::UNIX_EPOCH)
            .unwrap()
            .as_secs_f64();
        
        galaxies.insert(name.clone(), GalaxyInfo {
            _name: name.clone(),
            memory_count: 0,
            created_at: now,
            last_accessed: now,
        });
        
        Ok(true)
    }

    fn switch_galaxy(&mut self, name: String) -> PyResult<bool> {
        let galaxies = self.galaxies.read().unwrap();
        
        if !galaxies.contains_key(&name) {
            return Ok(false);
        }
        
        drop(galaxies);
        
        let mut active = self.active_galaxy.write().unwrap();
        *active = Some(name.clone());
        
        let mut galaxies = self.galaxies.write().unwrap();
        if let Some(info) = galaxies.get_mut(&name) {
            info.last_accessed = std::time::SystemTime::now()
                .duration_since(std::time::UNIX_EPOCH)
                .unwrap()
                .as_secs_f64();
        }
        
        Ok(true)
    }

    fn get_active_galaxy(&self) -> PyResult<Option<String>> {
        Ok(self.active_galaxy.read().unwrap().clone())
    }

    fn list_galaxies(&self) -> PyResult<Vec<String>> {
        let galaxies = self.galaxies.read().unwrap();
        Ok(galaxies.keys().cloned().collect())
    }

    fn delete_galaxy(&mut self, name: String) -> PyResult<bool> {
        let mut galaxies = self.galaxies.write().unwrap();
        Ok(galaxies.remove(&name).is_some())
    }

    fn get_galaxy_stats(&self, name: String) -> PyResult<Option<(usize, f64, f64)>> {
        let galaxies = self.galaxies.read().unwrap();
        
        Ok(galaxies.get(&name).map(|info| {
            (info.memory_count, info.created_at, info.last_accessed)
        }))
    }

    fn update_memory_count(&mut self, galaxy: String, count: usize) -> PyResult<bool> {
        let mut galaxies = self.galaxies.write().unwrap();
        
        if let Some(info) = galaxies.get_mut(&galaxy) {
            info.memory_count = count;
            Ok(true)
        } else {
            Ok(false)
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_create_galaxy() {
        let mut manager = PyGalaxyManagerV2::new();
        assert!(manager.create_galaxy("test".to_string()).unwrap());
        assert!(!manager.create_galaxy("test".to_string()).unwrap());
    }

    #[test]
    fn test_switch_galaxy() {
        let mut manager = PyGalaxyManagerV2::new();
        manager.create_galaxy("test".to_string()).unwrap();
        assert!(manager.switch_galaxy("test".to_string()).unwrap());
        assert_eq!(manager.get_active_galaxy().unwrap(), Some("test".to_string()));
    }

    #[test]
    fn test_list_galaxies() {
        let mut manager = PyGalaxyManagerV2::new();
        manager.create_galaxy("galaxy1".to_string()).unwrap();
        manager.create_galaxy("galaxy2".to_string()).unwrap();
        
        let galaxies = manager.list_galaxies().unwrap();
        assert_eq!(galaxies.len(), 2);
    }
}
