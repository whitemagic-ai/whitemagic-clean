%%% WhiteMagic Erlang Core - 14th Polyglot Implementation
%%% Distributed fault-tolerance, hot code reloading, BEAM VM

-module(wm_memory_core).
-export([new_store/0, add_memory/2, get_memory/2, similarity/2]).

-record(memory, {
    id :: binary(),
    content :: binary(),
    tags :: list(binary()),
    importance :: float()
}).

-type memory() :: #memory{}.
-type store() :: #{binary() => memory()}.

new_store() -> #{}.

add_memory(Store, Mem) ->
    Store#{Mem#memory.id => Mem}.

get_memory(Store, Id) ->
    maps:get(Id, Store, undefined).

%% Jaccard similarity for FFI calls
similarity(A, B) ->
    SetA = sets:from_list(binary:split(A, <<" ">>, [global, trim_all])),
    SetB = sets:from_list(binary:split(B, <<" ">>, [global, trim_all])),
    Intersection = sets:intersection(SetA, SetB),
    Union = sets:union(SetA, SetB),
    case sets:size(Union) of
        0 -> 0.0;
        N -> sets:size(Intersection) / N
    end.
