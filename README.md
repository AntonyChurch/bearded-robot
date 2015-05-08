# pioe
Erlang library for controlling Raspberry Pi GPIO pins

The module will connect to a C library which in turn controls the GPIO on the Raspberry Pi.

To connect Erlang to C an example was taken from the book: [Programming Erlang] (https://pragprog.com/book/jaerlang2/programming-erlang)

This module makes use of the WiringPi library as a simpler method for controlling the GPIO from C.

At this point, the only working thing is a barebones test driver for Erlang/C.

#Limitations
Currently you can only turn ports on and off. 

#Compilation
To Compile the C application:
`gcc interface.c interface_driver.c erl_comm.c -lwiringPi -o interface`

To Compile the Erlang Module:
`erlc connector.erl`
**Make sure to run your executable (or Erlang terminal) as root!**
