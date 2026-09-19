/*
============================================================================
Name        : 26_a.c
Author      : Bhumika
Description : Execute an external executable using execlp().
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    printf("Executing ls -l /tmp\n");

    execlp("ls", "ls", "-l", "/tmp", (char *)NULL);

    perror("execlp");
    return EXIT_FAILURE;
}

/*
============================================================================
Commands Used:

gcc 26_a.c -o 26_a
./26_a

Sample Output / Observation:

Executing ls -l /tmp
<contents of /tmp are displayed>
============================================================================
*/
