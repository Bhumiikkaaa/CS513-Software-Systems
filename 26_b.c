/*
============================================================================
Name        : 26_b.c
Author      : Bhumika
Description : Execute an external executable and pass an argument using
              execlp().
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    printf("Executing echo with an argument\n");

    execlp("echo", "echo", "Bhumika", (char *)NULL);

    perror("execlp");
    return EXIT_FAILURE;
}

/*
============================================================================
Commands Used:

gcc 26_b.c -o 26_b
./26_b

Sample Output / Observation:

Executing echo with an argument
Bhumika
============================================================================
*/
