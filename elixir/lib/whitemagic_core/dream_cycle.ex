defmodule WhitemagicCore.DreamCycle do
  use GenServer
  require Logger
  alias WhitemagicCore.Brain

  @moduledoc """
  Autonomous process that wakes up periodically to consolidate memories.
  "Interconnection with local models... autonomous capabilities."
  """
  
  # 5 minutes in milliseconds for the dream cycle tick
  @interval 5 * 60 * 1000
  # For demo: 5 seconds startup delay
  @initial_delay 5_000

  @phases [
    "triage",
    "consolidation",
    "serendipity",
    "governance",
    "narrative",
    "kaizen",
    "oracle",
    "decay",
    "constellation",
    "prediction",
    "enrichment",
    "harmonize"
  ]

  def start_link(_opts) do
    GenServer.start_link(__MODULE__, %{phase_index: 0, last_activity: System.monotonic_time(:second)}, name: __MODULE__)
  end

  @impl true
  def init(state) do
    Logger.info("🌙 Dream Cycle initialized. Monitoring idle periods...")
    Process.send_after(self(), :check_idle, @initial_delay)
    {:ok, state}
  end

  @impl true
  def handle_info(:check_idle, state) do
    current_time = System.monotonic_time(:second)
    idle_seconds = current_time - state.last_activity
    # 120s idle threshold from Python spec
    idle_threshold = 120

    if idle_seconds >= idle_threshold do
      send(self(), :dream)
    else
      Process.send_after(self(), :check_idle, 30_000) # Check again in 30s
    end

    {:noreply, state}
  end

  @impl true
  def handle_info(:dream, state) do
    phase = Enum.at(@phases, state.phase_index)
    Logger.info("🌌 Entering Dream Phase: #{phase}...")

    # Broadcast phase start
    WhitemagicCore.GardenPubSub.publish("garden:center", :dream_phase_start, %{phase: phase})

    results = run_phase(phase)

    # Broadcast phase complete
    WhitemagicCore.GardenPubSub.publish("garden:center", :dream_phase_complete, %{
      phase: phase,
      results: results
    })

    new_index = rem(state.phase_index + 1, length(@phases))

    # Schedule next check
    Process.send_after(self(), :check_idle, @interval)
    {:noreply, %{state | phase_index: new_index}}
  end

  @impl true
  def handle_cast(:touch, state) do
    {:noreply, %{state | last_activity: System.monotonic_time(:second)}}
  end

  # ---------------------------------------------------------------------------
  # Phase Execution logic
  # ---------------------------------------------------------------------------
  defp run_phase(phase) do
    memory_path = Path.expand("../../memories", File.cwd!())

    case Brain.execute_phase(phase, %{dir: memory_path}) do
      %{"status" => "ok", "details" => details} ->
        Logger.info("✨ Dream Phase #{phase} Complete")
        details
      err ->
        Logger.warning("☁️ Dream phase #{phase} interrupted: #{inspect(err)}")
        %{error: inspect(err)}
    end
  end
end
