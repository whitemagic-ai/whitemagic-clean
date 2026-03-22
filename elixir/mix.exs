defmodule WhiteMagic.MixProject do
  use Mix.Project

  def project do
    [
      app: :whitemagic_core,
      version: "20.0.0",
      elixir: "~> 1.14",
      start_permanent: Mix.env() == :prod,
      deps: deps()
    ]
  end

  def application do
    [
      extra_applications: [:logger],
      mod: {WhitemagicCore.Application, []}
    ]
  end

  defp deps do
    [
      {:rustler, "~> 0.32.1", runtime: false},
      {:libcluster, "~> 3.3"},
      {:ecto_sqlite3, "~> 0.13"},
      {:ecto, "~> 3.10"},
      {:jason, "~> 1.4"},
      {:redix, "~> 1.2"},
      {:yaml_elixir, "~> 2.9"},
      {:file_system, "~> 0.2.10"}
    ]
  end
end
