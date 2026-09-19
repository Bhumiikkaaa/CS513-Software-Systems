/*
============================================================================
Name        : 27.c
Author      : Bhumika
Description : Execute 'ls -Rl' using different exec* variants.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    printf("Parent PID = %d: Executing 'ls -Rl'\n", getpid());

    // Using execl
    printf("\n--- Using execl ---\n");
    if (fork() == 0)
    {
        execl("/bin/ls", "ls", "-Rl", (char *)NULL);
        perror("execl");
        exit(1);
    }
    wait(NULL);

    // Using execlp
    printf("\n--- Using execlp ---\n");
    if (fork() == 0)
    {
        execlp("ls", "ls", "-Rl", (char *)NULL);
        perror("execlp");
        exit(1);
    }
    wait(NULL);

    // Using execle
    printf("\n--- Using execle ---\n");
    if (fork() == 0)
    {
        char *envp[] = {"PATH=/bin", NULL};

        execle("/bin/ls", "ls", "-Rl", (char *)NULL, envp);
        perror("execle");
        exit(1);
    }
    wait(NULL);

    // Using execv
    printf("\n--- Using execv ---\n");
    if (fork() == 0)
    {
        char *args[] = {"ls", "-Rl", NULL};

        execv("/bin/ls", args);
        perror("execv");
        exit(1);
    }
    wait(NULL);

    // Using execvp
    printf("\n--- Using execvp ---\n");
    if (fork() == 0)
    {
        char *args[] = {"ls", "-Rl", NULL};

        execvp("ls", args);
        perror("execvp");
        exit(1);
    }
    wait(NULL);

    return 0;
}

/*
============================================================================
Commands Used:

gcc 27.c -o 27
./27

Sample Output / Observation:

Parent PID = <PID>: Executing 'ls -Rl'

--- Using execl ---
<recursive listing>

--- Using execlp ---
<recursive listing>

--- Using execle ---
<recursive listing>

--- Using execv ---
<recursive listing>

--- Using execvp ---
<recursive listing>
============================================================================
*/
