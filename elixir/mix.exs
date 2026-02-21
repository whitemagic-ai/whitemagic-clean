defmodule WhiteMagic.MixProject do
  use Mix.Project

  def project do
    [
      app: :whitemagic,
      version: "17.0.0",
      elixir: "~> 1.16",
      start_permanent: Mix.env() == :prod,
      deps: deps()
    ]
  end

  def application do
    [
      extra_applications: [:logger],
      mod: {WhiteMagic.Application, []}
    ]
  end

  defp deps do
    [
      {:rustler, "~> 0.30.0", runtime: false},
      {:libcluster, "~> 3.3"}
    ]
  end
end
