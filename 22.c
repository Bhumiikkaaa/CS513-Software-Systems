/*
============================================================================
Name        : 22.c
Author      : Bhumika
Description : Open a file, create a child process using fork(), and write
              to the file from both the parent and child processes.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
{
    int fd;
    pid_t pid;

    fd = open("file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd < 0)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid < 0)
    {
        perror("fork");
        close(fd);
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        write(fd, "Child Process\n", 14);
    }
    else
    {
        write(fd, "Parent Process\n", 15);
    }

    close(fd);

    return 0;
}

/*
============================================================================
Commands Used:

gcc 22.c -o 22
./22
cat file.txt

Sample Output / Observation:

Parent Process
Child Process

OR

Child Process
Parent Process

The order may vary because the parent and child processes execute
independently after fork().
============================================================================
*/
