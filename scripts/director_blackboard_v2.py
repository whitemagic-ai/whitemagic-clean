import collections
import json
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
                event = data.get("input_event", {})

                if event.get("type") == "file_scout":
                    BLACKBOARD["total_files_scanned"] += 1
                    path = event.get("path", "")

                    if not path:
                        continue

                    ext = path.split('.')[-1] if '.' in path else 'unknown'
                    BLACKBOARD["languages"][ext] += 1

                    parts = path.split('/')
                    base_dir = '/'.join(parts[:5]) if len(parts) >= 5 else path
                    BLACKBOARD["directories"][base_dir] += 1

                    if event.get("interesting"):
                        BLACKBOARD["interesting_files"].append({
                            "path": path,
                            "size": event.get("size", 0)
                        })

                elif event.get("type") == "swarm_complete":
                    print(f"\\n[Director] Received SWARM COMPLETE signal! Evaluated {event.get('files_scanned')} total items.")
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

def main():
    print("Director Subagent: Booting Koka Fast Brain...")

    # Start Koka Brain
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
    elixir_proc = subprocess.Popen(
        ['mix', 'run', '--no-start', 'swarm_scout.exs'],
        cwd='/home/lucas/Desktop/whitemagicdev/elixir',
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True
    )

    err_thread2 = threading.Thread(target=print_stderr, args=(elixir_proc, "Elixir"), daemon=True)
    err_thread2.start()

    start_time = time.time()
    try:
        while not BLACKBOARD["completed"] and time.time() - start_time < 60:
            time.sleep(1)
            sys.stdout.write(f"\\r[Blackboard] Files Scanned: {BLACKBOARD['total_files_scanned']} | Interesting: {len(BLACKBOARD['interesting_files'])}")
            sys.stdout.flush()
    except KeyboardInterrupt:
        pass

    print("\\n\\nDirector Subagent: Swarm execution finished. Terminating processes...")
    elixir_proc.terminate()
    koka_proc.terminate()

    if BLACKBOARD["errors"]:
        print("\\nErrors Encountered:")
        for err in BLACKBOARD["errors"]:
            print(err)

    report_path = "/home/lucas/Desktop/whitemagicdev/reports/SCOUT_SWARM_INTELLIGENCE.md"
    print(f"\\nWriting Intelligence Report to {report_path}...")

    with open(report_path, "w") as f:
        f.write("# Scout Swarm Intelligence Report\\n\\n")
        f.write(f"**Total Files Scanned:** {BLACKBOARD['total_files_scanned']}\\n")
        f.write(f"**Interesting Target Files:** {len(BLACKBOARD['interesting_files'])}\\n\\n")

        f.write("## Target Ecosystem Breakdown\\n")
        for dir_path, count in BLACKBOARD["directories"].most_common():
            f.write(f"- `{dir_path}`: {count} files\\n")

        f.write("\\n## Language Distribution\\n")
        for ext, count in BLACKBOARD["languages"].most_common(20):
            f.write(f"- `.{ext}`: {count} files\\n")

        f.write("\\n## Top 50 Largest Interesting Files (Candidates for Analysis/Refactoring)\\n")

        sorted_files = sorted(BLACKBOARD["interesting_files"], key=lambda x: x["size"], reverse=True)
        for i, file_obj in enumerate(sorted_files[:50]):
            size_kb = file_obj["size"] / 1024
            f.write(f"{i+1}. `{file_obj['path']}` ({size_kb:.2f} KB)\\n")

    print("Done. Check the intelligence report.")

if __name__ == "__main__":
    main()
