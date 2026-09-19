/*
============================================================================
Name        : 21.c
Author      : Bhumika
Description : Create a child process using fork() and print the
              parent and child process IDs.
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
        printf("Parent PID : %d\n", getppid());
    }
    else
    {
        printf("Parent Process\n");
        printf("Parent PID : %d\n", getpid());
        printf("Child PID  : %d\n", pid);
    }

    return 0;
}

/*
============================================================================
Commands Used:

gcc 21.c -o 21
./21

Sample Output / Observation:

Parent Process
Parent PID  : 1234
Child PID   : 1235

Child Process
Child PID   : 1235
Parent PID  : 1234
============================================================================
*/
