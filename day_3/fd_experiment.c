/*
============================================================================
Name        : fd_experiment.c
Author      : Bhumika
Description : Demonstrate file descriptor allocation and reuse using the
              creat() and close() system calls.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd1, fd2, fd3;

    fd1 = creat("file1.txt", 0644);
    printf("file1.txt -> FD = %d\n", fd1);

    fd2 = creat("file2.txt", 0644);
    printf("file2.txt -> FD = %d\n", fd2);

    fd3 = creat("file3.txt", 0644);
    printf("file3.txt -> FD = %d\n", fd3);

    close(fd2);

    printf("\nClosed FD %d (file2.txt)\n", fd2);

    int fd4 = creat("file4.txt", 0644);
    printf("file4.txt -> FD = %d\n", fd4);

    close(fd1);
    close(fd3);
    close(fd4);

    return 0;
}

/*
============================================================================
Commands Used:
----------------------------------------------------------------------------

Compilation:
gcc fd_experiment.c -o fd_experiment

Execution:
./fd_experiment

Inspect the created files:
ls -l file1.txt file2.txt file3.txt file4.txt

============================================================================
Sample Output / Observation:
----------------------------------------------------------------------------

file1.txt -> FD = 3
file2.txt -> FD = 4
file3.txt -> FD = 5

Closed FD 4 (file2.txt)
file4.txt -> FD = 4

Observation:

After FD 4 was closed, Linux reused FD 4 when creating file4.txt.
This demonstrates that Linux generally assigns the lowest available
file descriptor.

============================================================================
*/
