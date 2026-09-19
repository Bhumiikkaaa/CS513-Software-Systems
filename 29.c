/*
============================================================================
Name        : 29.c
Author      : Bhumika
Description : Get and modify the scheduling policy using SCHED_FIFO
              and SCHED_RR.
============================================================================
*/

#include <stdio.h>
#include <sched.h>
#include <stdlib.h>

void print_policy(int policy)
{
    if (policy == SCHED_FIFO)
        printf("Scheduling Policy : SCHED_FIFO\n");
    else if (policy == SCHED_RR)
        printf("Scheduling Policy : SCHED_RR\n");
    else if (policy == SCHED_OTHER)
        printf("Scheduling Policy : SCHED_OTHER\n");
    else
        printf("Scheduling Policy : Unknown\n");
}

int main()
{
    int policy;
    struct sched_param param;

    policy = sched_getscheduler(0);

    if (policy == -1)
    {
        perror("sched_getscheduler");
        return EXIT_FAILURE;
    }

    printf("Initial ");
    print_policy(policy);

    param.sched_priority = sched_get_priority_min(SCHED_FIFO);

    if (sched_setscheduler(0, SCHED_FIFO, &param) == -1)
    {
        perror("sched_setscheduler SCHED_FIFO");
        return EXIT_FAILURE;
    }

    policy = sched_getscheduler(0);
    printf("After modification ");
    print_policy(policy);

    param.sched_priority = sched_get_priority_min(SCHED_RR);

    if (sched_setscheduler(0, SCHED_RR, &param) == -1)
    {
        perror("sched_setscheduler SCHED_RR");
        return EXIT_FAILURE;
    }

    policy = sched_getscheduler(0);
    printf("After modification ");
    print_policy(policy);

    return 0;
}

/*
============================================================================
Commands Used:

gcc 29.c -o 29
./29

Sample Output / Observation:

Initial Scheduling Policy : SCHED_OTHER
After modification Scheduling Policy : SCHED_FIFO
After modification Scheduling Policy : SCHED_RR
============================================================================
*/
