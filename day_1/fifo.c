/*
============================================================================
Name        : fifo.c
Author      : Bhumika
Description : Create a FIFO (named pipe) using the mkfifo() system call.
============================================================================
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    if (mkfifo("myfifo_from_c", 0666) == -1)
    {
        perror("mkfifo failed");
        return 1;
    }

    printf("FIFO created successfully\n");

    return 0;
}

/*
============================================================================
Commands Used:
----------------------------------------------------------------------------

Compilation:
gcc fifo.c -o fifo

Execution:
./fifo

Inspect the FIFO:
ls -l myfifo_from_c

============================================================================
Sample Output / Observation:
----------------------------------------------------------------------------

FIFO created successfully

The first character in the ls -l output is:

p

This indicates that the file is a FIFO (named pipe).

============================================================================
*/
