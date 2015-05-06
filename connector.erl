-module(connector).

-export([start/0, stop/0]).
-export([add/2, multiply/2, square/1, onoff/2]).

start() ->
  register(connector,
            spawn(fun() ->
                    process_flag(trap_exit, true),
                    Port = open_port({spawn, "./test1"}, [{packet, 2}]),
                    loop(Port)
                 end)).

stop() ->
  ?MODULE ! stop.

add(X, Y) -> call_port({add, X, Y}).
multiply(X, Y) -> call_port({multiply, X, Y}).
square(X) -> call_port({square, X}).
onoff(Port, Direction) -> call_port({onoff, Port, Direction}).

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

  encode({add, X, Y}) -> [1, X, Y];
  encode({multiply, X, Y}) -> [2, X, Y];
  encode({square, X}) -> [3, X];
  encode({onoff, Port, Direction}) -> [4, Port, Direction].

  decode([Int]) -> Int.
