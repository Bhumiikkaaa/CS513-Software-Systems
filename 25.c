/*
============================================================================
Name        : 25.c
Author      : Bhumika
Description : Create three child processes and use waitpid() to make the
              parent wait for a particular child process.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    pid_t pid1, pid2, pid3;
    int status;

    pid1 = fork();

    if (pid1 < 0)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid1 == 0)
    {
        printf("Child 1: PID = %d\n", getpid());
        sleep(2);
        printf("Child 1 exiting\n");
        exit(1);
    }

    pid2 = fork();

    if (pid2 < 0)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid2 == 0)
    {
        printf("Child 2: PID = %d\n", getpid());
        sleep(5);
        printf("Child 2 exiting\n");
        exit(2);
    }

    pid3 = fork();

    if (pid3 < 0)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid3 == 0)
    {
        printf("Child 3: PID = %d\n", getpid());
        sleep(3);
        printf("Child 3 exiting\n");
        exit(3);
    }

    printf("Parent: PID = %d\n", getpid());
    printf("Parent waiting specifically for Child 2: PID = %d\n", pid2);

    waitpid(pid2, &status, 0);

    if (WIFEXITED(status))
    {
        printf("Child 2 terminated with exit status %d\n",
               WEXITSTATUS(status));
    }

    printf("Parent finished waiting for Child 2\n");

    return 0;
}

/*
============================================================================
Commands Used:

gcc 25.c -o 25
./25

Sample Output / Observation:

Parent: PID = 19000
Parent waiting specifically for Child 2: PID = 19002

Child 1: PID = 19001
Child 2: PID = 19002
Child 3: PID = 19003

Child 1 exiting
Child 3 exiting
Child 2 exiting
Child 2 terminated with exit status 2
Parent finished waiting for Child 2

The parent uses waitpid() to specifically wait for Child 2.

============================================================================
*/
