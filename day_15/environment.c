 /*
 ============================================================================
 Name        : environment.c
 Author      : Bhumika
 Description : Displays the environment variables of the user using environ.
 ============================================================================
 */

#include <stdio.h>

extern char **environ;

int main()
{
    char **env = environ;

    while (*env != NULL)
    {
        printf("%s\n", *env);
        env++;
    }

    return 0;
}

/*
 ============================================================================
 Commands Used:

 gcc environment.c -o environment
 ./environment

 Sample Output / Observation:

 USER=bhumika
 HOME=/home/bhumika
 PATH=...
 ...
 ============================================================================
 */
