# pioe
Erlang library for controlling Raspberry Pi GPIO pins

The module will connect to a C library which in turn controls the GPIO on the Raspberry Pi.

This module makes use of the WiringPi library as a simpler method for controlling the GPIO from C.

At this point, the only working thing is a barebones test driver for Erlang/C.

#Todo
1. Figure out process for starting WiringPi.
2. Controlling set pinModes in WiringPi from Erlang.
3. Write the C library.
4. Write the actual Erlang Module.
5. Create the make file(s).
