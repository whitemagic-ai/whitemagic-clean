//! SQLite Backend - Database Operations (PSR-001)
//! Target: 20-50× speedup over Python sqlite3

use pyo3::prelude::*;
use rusqlite::{Connection, params, Result as SqlResult};
use std::sync::{Arc, Mutex};

#[pyclass]
pub struct PySQLiteBackend {
    conn: Arc<Mutex<Connection>>,
}

#[pymethods]
impl PySQLiteBackend {
    #[new]
    fn new(db_path: String) -> PyResult<Self> {
        let conn = Connection::open(&db_path)
            .map_err(|e| PyErr::new::<pyo3::exceptions::PyRuntimeError, _>(
                format!("Failed to open database: {}", e)
            ))?;
        
        Ok(Self {
            conn: Arc::new(Mutex::new(conn)),
        })
    }

    fn execute(&self, sql: String, params_list: Vec<String>) -> PyResult<usize> {
        let conn = self.conn.lock()
            .map_err(|e| PyErr::new::<pyo3::exceptions::PyRuntimeError, _>(
                format!("Lock error: {}", e)
            ))?;
        
        let params_refs: Vec<&dyn rusqlite::ToSql> = params_list
            .iter()
            .map(|s| s as &dyn rusqlite::ToSql)
            .collect();
        
        conn.execute(&sql, params_refs.as_slice())
            .map_err(|e| PyErr::new::<pyo3::exceptions::PyRuntimeError, _>(
                format!("Execute failed: {}", e)
            ))
    }

    fn query_one(&self, sql: String) -> PyResult<Option<String>> {
        let conn = self.conn.lock()
            .map_err(|e| PyErr::new::<pyo3::exceptions::PyRuntimeError, _>(
                format!("Lock error: {}", e)
            ))?;
        
        let mut stmt = conn.prepare(&sql)
            .map_err(|e| PyErr::new::<pyo3::exceptions::PyRuntimeError, _>(
                format!("Prepare failed: {}", e)
            ))?;
        
        let result = stmt.query_row([], |row| row.get::<_, String>(0));
        
        match result {
            Ok(val) => Ok(Some(val)),
            Err(rusqlite::Error::QueryReturnedNoRows) => Ok(None),
            Err(e) => Err(PyErr::new::<pyo3::exceptions::PyRuntimeError, _>(
                format!("Query failed: {}", e)
            )),
        }
    }

    fn batch_insert(&self, table: String, rows: Vec<Vec<String>>) -> PyResult<usize> {
        let conn = self.conn.lock()
            .map_err(|e| PyErr::new::<pyo3::exceptions::PyRuntimeError, _>(
                format!("Lock error: {}", e)
            ))?;
        
        let tx = conn.unchecked_transaction()
            .map_err(|e| PyErr::new::<pyo3::exceptions::PyRuntimeError, _>(
                format!("Transaction failed: {}", e)
            ))?;
        
        let mut count = 0;
        for row in rows {
            let placeholders = vec!["?"; row.len()].join(", ");
            let sql = format!("INSERT INTO {} VALUES ({})", table, placeholders);
            
            let params_refs: Vec<&dyn rusqlite::ToSql> = row
                .iter()
                .map(|s| s as &dyn rusqlite::ToSql)
                .collect();
            
            tx.execute(&sql, params_refs.as_slice())
                .map_err(|e| PyErr::new::<pyo3::exceptions::PyRuntimeError, _>(
                    format!("Insert failed: {}", e)
                ))?;
            count += 1;
        }
        
        tx.commit()
            .map_err(|e| PyErr::new::<pyo3::exceptions::PyRuntimeError, _>(
                format!("Commit failed: {}", e)
            ))?;
        
        Ok(count)
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rusqlite::Connection;

    #[test]
    fn test_connection() {
        let conn = Connection::open_in_memory().unwrap();
        assert!(conn.is_autocommit());
    }

    #[test]
    fn test_create_table() {
        let conn = Connection::open_in_memory().unwrap();
        conn.execute(
            "CREATE TABLE test (id INTEGER PRIMARY KEY, name TEXT)",
            [],
        ).unwrap();
    }

    #[test]
    fn test_insert_and_query() {
        let conn = Connection::open_in_memory().unwrap();
        conn.execute(
            "CREATE TABLE test (id INTEGER PRIMARY KEY, name TEXT)",
            [],
        ).unwrap();
        
        conn.execute(
            "INSERT INTO test (id, name) VALUES (?1, ?2)",
            params![1, "Alice"],
        ).unwrap();
        
        let name: String = conn.query_row(
            "SELECT name FROM test WHERE id = ?1",
            params![1],
            |row| row.get(0),
        ).unwrap();
        
        assert_eq!(name, "Alice");
    }

    #[test]
    fn test_batch_transaction() {
        let conn = Connection::open_in_memory().unwrap();
        conn.execute(
            "CREATE TABLE test (id INTEGER PRIMARY KEY, value INTEGER)",
            [],
        ).unwrap();
        
        let tx = conn.unchecked_transaction().unwrap();
        for i in 0..1000 {
            tx.execute(
                "INSERT INTO test (id, value) VALUES (?1, ?2)",
                params![i, i * 2],
            ).unwrap();
        }
        tx.commit().unwrap();
        
        let count: i64 = conn.query_row(
            "SELECT COUNT(*) FROM test",
            [],
            |row| row.get(0),
        ).unwrap();
        
        assert_eq!(count, 1000);
    }
}
