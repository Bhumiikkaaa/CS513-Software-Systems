/*
============================================================================
Name        : write_lock.c
Author      : Bhumika
Description : Demonstrates a write lock using fcntl().
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    struct flock lock;

    fd = open("lockfile", O_RDWR | O_CREAT, 0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    printf("Waiting to acquire write lock...\n");

    if (fcntl(fd, F_SETLKW, &lock) == -1)
    {
        perror("fcntl");
        close(fd);
        return 1;
    }

    printf("Write lock acquired.\n");
    printf("Lock is held. Press Enter to release it.\n");

    getchar();

    lock.l_type = F_UNLCK;

    if (fcntl(fd, F_SETLK, &lock) == -1)
    {
        perror("fcntl");
        close(fd);
        return 1;
    }

    printf("Write lock released.\n");

    close(fd);

    return 0;
}

/*
============================================================================
Commands Used:

gcc write_lock.c -o write_lock
./write_lock

Sample Output / Observation:

Waiting to acquire write lock...
Write lock acquired.
Lock is held. Press Enter to release it.
Write lock released.
============================================================================
*/
