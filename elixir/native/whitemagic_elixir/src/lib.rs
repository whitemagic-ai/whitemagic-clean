use rustler::{Env, Term, Error, NifResult, Atom};
use std::sync::Mutex;
use std::ffi::CString;
use std::ptr;
use libc::{shm_open, mmap, O_CREAT, O_RDWR, PROT_READ, PROT_WRITE, MAP_SHARED, ftruncate, close};
use std::sync::OnceLock;

mod atoms {
    rustler::atoms! {
        ok,
        error,
        shm_init_failed,
        ring_full,
    }
}

const MAGIC: i32 = 0x52494E47;
const HEADER_SIZE: usize = 64;
const SLOT_SIZE: usize = 256;
const CAPACITY: usize = 65536;
const SEGMENT_SIZE: usize = HEADER_SIZE + (CAPACITY * SLOT_SIZE);

struct ShmRing {
    addr: *mut libc::c_void,
}

unsafe impl Send for ShmRing {}
unsafe impl Sync for ShmRing {}

static SHM_RING: OnceLock<Mutex<ShmRing>> = OnceLock::new();

#[rustler::nif]
fn init_shm_ring() -> NifResult<Atom> {
    let name = CString::new("/whitemagic_event_ring").unwrap();
    
    unsafe {
        let fd = shm_open(name.as_ptr(), O_CREAT | O_RDWR, 0o666);
        if fd < 0 {
            return Err(Error::Term(Box::new(atoms::shm_init_failed())));
        }
        
        ftruncate(fd, SEGMENT_SIZE as i64);
        
        let addr = mmap(
            ptr::null_mut(),
            SEGMENT_SIZE,
            PROT_READ | PROT_WRITE,
            MAP_SHARED,
            fd,
            0,
        );
        
        close(fd);
        
        if addr == libc::MAP_FAILED {
            return Err(Error::Term(Box::new(atoms::shm_init_failed())));
        }
        
        // Initialize header
        let magic_ptr = addr as *mut i32;
        if *magic_ptr != MAGIC {
            *magic_ptr = MAGIC;
            *((addr as *mut i32).offset(1)) = 0; // head
            *((addr as *mut i32).offset(2)) = 0; // tail
            *((addr as *mut i32).offset(3)) = CAPACITY as i32; // capacity
        }
        
        let _ = SHM_RING.set(Mutex::new(ShmRing { addr }));
    }
    
    Ok(atoms::ok())
}

#[rustler::nif]
fn push_event(event_type: i32, sender_hash: i32, timestamp: f64, payload: String) -> NifResult<Atom> {
    let ring_mutex = match SHM_RING.get() {
        Some(m) => m,
        None => return Err(Error::Term(Box::new(atoms::shm_init_failed()))),
    };
    
    let ring = ring_mutex.lock().unwrap();
    let addr = ring.addr;
    
    unsafe {
        let head_ptr = (addr as *mut i32).offset(1);
        let tail_ptr = (addr as *mut i32).offset(2);
        
        let head = std::ptr::read_volatile(head_ptr);
        let tail = std::ptr::read_volatile(tail_ptr);
        
        let next_head = (head + 1) % (CAPACITY as i32);
        if next_head == tail {
            return Err(Error::Term(Box::new(atoms::ring_full())));
        }
        
        let offset = HEADER_SIZE + (head as usize * SLOT_SIZE);
        let slot_ptr = (addr as *mut u8).add(offset);
        
        // Write slot header
        *(slot_ptr as *mut i32) = event_type;
        *((slot_ptr as *mut i32).offset(1)) = sender_hash;
        *((slot_ptr as *mut f64).offset(1)) = timestamp; // offset is 8 bytes, so 1 * f64
        
        // Write payload
        let payload_ptr = slot_ptr.add(16);
        let payload_bytes = payload.as_bytes();
        let copy_len = std::cmp::min(payload_bytes.len(), 239); // 256 - 16 - 1 (null term)
        
        std::ptr::copy_nonoverlapping(payload_bytes.as_ptr(), payload_ptr, copy_len);
        *payload_ptr.add(copy_len) = 0; // null terminator
        
        // Update head
        std::ptr::write_volatile(head_ptr, next_head);
    }
    
    Ok(atoms::ok())
}

rustler::init!("Elixir.WhiteMagic.EventRing.Nif", [init_shm_ring, push_event]);
