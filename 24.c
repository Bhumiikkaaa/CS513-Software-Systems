/*
============================================================================
Name        : 24.c
Author      : Bhumika
Description : Create an orphan process by terminating the parent process
              while the child process continues to run.
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
        printf("Child PID  : %d\n", getpid());
        printf("Initial Parent PID : %d\n", getppid());

        sleep(10);

        printf("After Parent Exits\n");
        printf("Child PID  : %d\n", getpid());
        printf("New Parent PID : %d\n", getppid());
    }
    else
    {
        printf("Parent Process\n");
        printf("Parent PID : %d\n", getpid());
        printf("Child PID  : %d\n", pid);

        sleep(2);

        printf("Parent is exiting...\n");
        exit(0);
    }

    return 0;
}

/*
============================================================================
Commands Used:

gcc 24.c -o 24
./24

Sample Output / Observation:

Parent Process
Parent PID : 18000
Child PID  : 18001

Child Process
Child PID  : 18001
Initial Parent PID : 18000

Parent is exiting...

After Parent Exits
Child PID  : 18001
New Parent PID : 1

The parent process terminates while the child is still running.
The child becomes an orphan and is adopted by another process.
============================================================================
*/
