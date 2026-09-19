/*
============================================================================
Name        : priority.c
Author      : Bhumika
Description : Displays the priority and nice value of the running program.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("PID: %d\n", getpid());

    printf("Run the following command in another terminal:\n");
    printf("ps -o pid,ni,pri,comm -p %d\n", getpid());

    printf("Press Enter to exit.\n");
    getchar();

    return 0;
}

/*
============================================================================
Commands Used:

gcc priority.c -o priority
./priority

In another terminal:

ps -o pid,ni,pri,comm -p <PID>

Sample Output / Observation:

PID: 12345
Run the following command in another terminal:
ps -o pid,ni,pri,comm -p 12345
Press Enter to exit.

============================================================================
*/
