/*
============================================================================
Name        : infinite_loop.c
Author      : Bhumika
Description : Run an infinite loop to create a continuously running process
              for exploring process information through the /proc filesystem.
============================================================================
*/

#include <stdio.h>

int main()
{
    while (1)
    {
    }

    return 0;
}

/*
============================================================================
Commands Used:
----------------------------------------------------------------------------

Compilation:
gcc infinite_loop.c -o infinite_loop

Run in the background:
./infinite_loop &

Check the process:
ps -p <PID>

Check process state and resource usage:
ps -p <PID> -o pid,stat,%cpu,%mem,cmd

Explore process information:
cat /proc/<PID>/status
cat /proc/<PID>/stat
cat /proc/<PID>/statm

============================================================================
Sample Output / Observation:
----------------------------------------------------------------------------

The program runs continuously and produces no terminal output.

When executed in the background:

[1] <PID>

Example process observation:

PID    STAT   %CPU   %MEM   CMD
<PID>  R      ~100   0.0    ./infinite_loop

The process consumes high CPU because the infinite loop continuously executes.

============================================================================
*/
