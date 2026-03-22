import collections
import json
import os
import subprocess
import sys
import threading
import time

# Global Blackboard
BLACKBOARD = {
    "total_files_scanned": 0,
    "interesting_files": [],
    "languages": collections.Counter(),
    "directories": collections.Counter(),
    "completed": False,
    "errors": []
}

def parse_koka_output(proc):
    global BLACKBOARD
    for line in proc.stdout:
        line = line.strip()
        if not line:
            continue

        try:
            if "telemetry_processed" in line:
                data = json.loads(line)
                input_event = data.get("input_event", {})
                payload = input_event.get("payload", {})

                # Check if payload is a string (sometimes JSON double-encoding happens)
                if isinstance(payload, str):
                    try:
                        payload = json.loads(payload)
                    except:
                        pass

                if isinstance(payload, dict) and payload.get("type") == "file_scout":
                    BLACKBOARD["total_files_scanned"] += 1
                    path = payload.get("path", "")

                    if not path:
                        continue

                    ext = path.split('.')[-1] if '.' in path else 'unknown'
                    BLACKBOARD["languages"][ext] += 1

                    parts = path.split('/')
                    base_dir = '/'.join(parts[:5]) if len(parts) >= 5 else path
                    BLACKBOARD["directories"][base_dir] += 1

                    if payload.get("interesting"):
                        BLACKBOARD["interesting_files"].append({
                            "path": path,
                            "size": payload.get("size", 0),
                            "score": payload.get("score", 0)
                        })

                elif isinstance(payload, dict) and payload.get("type") == "swarm_complete":
                    print(f"\\n[Director] Received SWARM COMPLETE signal! Evaluated {payload.get('files_scanned')} total items.")
                    BLACKBOARD["completed"] = True

        except json.JSONDecodeError:
            pass
        except Exception:
            pass

def print_stderr(proc, name):
    for line in proc.stderr:
        line = line.strip()
        if line:
            BLACKBOARD["errors"].append(f"[{name}] {line}")

def print_stdout(proc, name):
    for line in proc.stdout:
        # Just consume it to prevent pipe blocking
        pass

def main():
    print("Director Subagent: Booting Koka Fast Brain...")

    try:
        os.remove("/dev/shm/whitemagic_event_ring")
    except Exception:
        pass

    koka_proc = subprocess.Popen(
        ['/home/lucas/Desktop/whitemagicdev/whitemagic-koka/unified_fast_brain'],
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True
    )

    reader_thread = threading.Thread(target=parse_koka_output, args=(koka_proc,), daemon=True)
    reader_thread.start()

    err_thread1 = threading.Thread(target=print_stderr, args=(koka_proc, "Koka"), daemon=True)
    err_thread1.start()

    time.sleep(1)

    print("Director Subagent: Launching Elixir Scout Swarm...")

    # We pipe stdout so we don't clutter the console, but we MUST consume it to prevent blocking
    elixir_proc = subprocess.Popen(
        ['mix', 'run', 'swarm_scout.exs'],
        cwd='/home/lucas/Desktop/whitemagicdev/elixir',
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True
    )

    out_thread2 = threading.Thread(target=print_stdout, args=(elixir_proc, "Elixir"), daemon=True)
    out_thread2.start()

    err_thread2 = threading.Thread(target=print_stderr, args=(elixir_proc, "Elixir"), daemon=True)
    err_thread2.start()

    start_time = time.time()
    try:
        # Give it up to 5 minutes to fully execute
        while not BLACKBOARD["completed"] and time.time() - start_time < 300:
            time.sleep(2)
            sys.stdout.write(f"\\r[Blackboard] Interesting Files Evaluated: {BLACKBOARD['total_files_scanned']} | Target Directories Hit: {len(BLACKBOARD['directories'])}")
            sys.stdout.flush()
    except KeyboardInterrupt:
        pass

    print("\\n\\nDirector Subagent: Swarm execution finished. Terminating processes...")
    elixir_proc.terminate()
    koka_proc.terminate()

    if BLACKBOARD["errors"]:
        print("\\nErrors Encountered:")
        for err in BLACKBOARD["errors"][:10]:
            print(err)

    report_path = "/home/lucas/Desktop/whitemagicdev/reports/SCOUT_SWARM_INTELLIGENCE.md"
    print(f"\\nWriting Intelligence Report to {report_path}...")

    with open(report_path, "w") as f:
        f.write("# Scout Swarm Intelligence Report\\n\\n")
        f.write(f"**Highly Interesting Target Files Identified:** {BLACKBOARD['total_files_scanned']}\\n\\n")

        f.write("## Target Ecosystem Breakdown\\n")
        for dir_path, count in BLACKBOARD["directories"].most_common(20):
            f.write(f"- `{dir_path}`: {count} interesting files\\n")

        f.write("\\n## Language Distribution of Interesting Files\\n")
        for ext, count in BLACKBOARD["languages"].most_common(20):
            f.write(f"- `.{ext}`: {count} files\\n")

        f.write("\\n## Top 100 Most Relevant Files (Sorted by Heuristic Score)\\n")

        sorted_files = sorted(BLACKBOARD["interesting_files"], key=lambda x: (x.get("score", 0), x.get("size", 0)), reverse=True)
        seen = set()
        count = 0
        for file_obj in sorted_files:
            if file_obj['path'] in seen:
                continue
            seen.add(file_obj['path'])
            size_kb = file_obj["size"] / 1024
            score = file_obj.get("score", 0)
            f.write(f"{count+1}. `{file_obj['path']}` (Score: {score}, {size_kb:.2f} KB)\\n")
            count += 1
            if count >= 100:
                break

    print("Done. Check the intelligence report.")

if __name__ == "__main__":
    main()
