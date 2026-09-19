/*
============================================================================
Name        : 23.c
Author      : Bhumika
Description : Create a zombie process by allowing the child to terminate
              while the parent does not call wait().
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
{
    pid_t pid;

    pid = fork();

    if (pid < 0)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        printf("Child Process\n");
        printf("Child PID : %d\n", getpid());
        printf("Child is exiting...\n");

        exit(0);
    }
    else
    {
        printf("Parent Process\n");
        printf("Parent PID : %d\n", getpid());
        printf("Child PID  : %d\n", pid);

        printf("Parent is sleeping for 20 seconds...\n");
        sleep(20);
    }

    return 0;
}

/*
============================================================================
Commands Used:

gcc 23.c -o 23
./23

In another terminal:

ps -o pid,ppid,state,comm -p <child_pid>

Sample Output / Observation:

Parent Process
Parent PID : 15000
Child PID  : 15001
Parent is sleeping for 20 seconds...

Child Process
Child PID : 15001
Child is exiting...

The child becomes a zombie because it has terminated but the parent
has not called wait() to collect its exit status.

============================================================================
*/
