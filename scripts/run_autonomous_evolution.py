import time
import subprocess
import datetime
from pathlib import Path

def is_midnight():
    now = datetime.datetime.now()
    return now.hour == 0 and now.minute == 0

def run_loop():
    print(f"[{datetime.datetime.now().isoformat()}] Starting Evolutionary Master Loop...")
    
    # Run the Geneseed test generator stub to show intent
    subprocess.run(["python3", "scripts/evolve_test_coverage.py"], check=False)
    
    # Run the Evolutionary Master loop
    subprocess.run(["python3", "scripts/evolutionary_master_loop.py"], check=False)
    
    print(f"[{datetime.datetime.now().isoformat()}] Cycle complete. Sleeping...")

def main():
    print("Starting Autonomous Evolution Engine until Midnight.")
    cycles = 0
    # Let's run just 3 cycles for demonstration rather than literally blocking until midnight
    while cycles < 3:
        if is_midnight():
            print("Midnight reached. Stopping.")
            break
            
        run_loop()
        cycles += 1
        time.sleep(2)
        
    print(f"Autonomous loop finished {cycles} cycles.")

if __name__ == "__main__":
    main()
