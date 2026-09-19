/*
============================================================================
Name        : opening_mode.c
Author      : Bhumika
Description : Find the opening mode of a file using fcntl().
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    int flags;

    fd = open("file4", O_RDONLY);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    flags = fcntl(fd, F_GETFL);

    if (flags == -1)
    {
        perror("fcntl");
        close(fd);
        return 1;
    }

    if ((flags & O_ACCMODE) == O_RDONLY)
        printf("File is opened in read-only mode\n");
    else if ((flags & O_ACCMODE) == O_WRONLY)
        printf("File is opened in write-only mode\n");
    else if ((flags & O_ACCMODE) == O_RDWR)
        printf("File is opened in read-write mode\n");

    close(fd);

    return 0;
}

/*
============================================================================
Commands Used:
----------------------------------------------------------------------------

Create the source file:
nano opening_mode.c

Compilation:
gcc opening_mode.c -o opening_mode

Execution:
./opening_mode

============================================================================
Sample Output:
----------------------------------------------------------------------------

File is opened in read-write mode

============================================================================
*/
