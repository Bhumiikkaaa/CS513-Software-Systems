/*
============================================================================
Name        : 28.c
Author      : Bhumika
Description : Get the maximum and minimum real-time scheduling priority.
============================================================================
*/

#include <stdio.h>
#include <sched.h>
#include <stdlib.h>

int main()
{
    int max_priority;
    int min_priority;

    max_priority = sched_get_priority_max(SCHED_FIFO);
    min_priority = sched_get_priority_min(SCHED_FIFO);

    if (max_priority == -1 || min_priority == -1)
    {
        perror("sched_get_priority");
        return EXIT_FAILURE;
    }

    printf("Maximum real-time priority : %d\n", max_priority);
    printf("Minimum real-time priority : %d\n", min_priority);

    return 0;
}

/*
============================================================================
Commands Used:

gcc 28.c -o 28
./28

Sample Output / Observation:

Maximum real-time priority : 99
Minimum real-time priority : 1
============================================================================
*/
