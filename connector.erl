-module(connector).

-export([start/0, stop/0]).
-export([turn_on/1, turn_off/1, setup/0]).

start() ->
  register(connector,
            spawn(fun() ->
                    process_flag(trap_exit, true),
                    Port = open_port({spawn, "./interface"}, [{packet, 2}]),
                    loop(Port)
                 end)).

stop() ->
  ?MODULE ! stop.

setup() -> call_port(setup).
turn_on(Port) -> call_port({turn_on, Port}).
turn_off(Port) -> call_port({turn_off, Port}).

call_port(Msg) ->
  ?MODULE ! {call, self(), Msg},
  receive
    {?MODULE, Result} ->
      Result
  end.

loop(Port) ->
  receive
    {call, Caller, Msg} ->
      Port ! {self(), {command, encode(Msg)}},
      receive
        {Port, {data, Data}} ->
          Caller ! {?MODULE, decode(Data)}
      end,
      loop(Port);
    stop ->
      Port ! {self(), close},
      receive
        {Port, closed} ->
          exit(normal)
      end;
    {'EXIT', Port, Reason} ->
      exit({port_terminated, Reason})
  end.

  encode(setup) -> [1];
  encode({turn_on, Port}) -> [2, Port];
  encode({turn_off, Port}) -> [3, Port].

  decode([Int]) -> Int.
