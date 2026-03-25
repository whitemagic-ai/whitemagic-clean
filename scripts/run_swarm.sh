#!/bin/bash

cd /home/lucas/Desktop/whitemagicdev/elixir

echo "Cleaning SHM..."
rm -f /dev/shm/whitemagic_event_ring

echo "Initializing SHM Ring..."
mix run -e "WhiteMagic.EventRing.Nif.init_shm_ring()"

echo "Starting Koka Fast Brain..."
/home/lucas/Desktop/whitemagicdev/whitemagic-koka/unified_fast_brain > /home/lucas/Desktop/whitemagicdev/koka_swarm_out.log &
KOKA_PID=$!

sleep 1

echo "Starting Elixir Scout Swarm..."
mix run swarm_scout.exs

echo "Waiting for Koka to process events..."
sleep 15

echo "Terminating Koka..."
kill -9 $KOKA_PID

echo "Processing results..."
python3 /home/lucas/Desktop/whitemagicdev/scripts/generate_report.py
