/*
============================================================================
Name        : read_lock.c
Author      : Bhumika
Description : Demonstrates a read lock using fcntl().
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

    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    printf("Waiting to acquire read lock...\n");

    if (fcntl(fd, F_SETLKW, &lock) == -1)
    {
        perror("fcntl");
        close(fd);
        return 1;
    }

    printf("Read lock acquired.\n");
    printf("Read lock is held. Press Enter to release it.\n");

    getchar();

    lock.l_type = F_UNLCK;

    if (fcntl(fd, F_SETLK, &lock) == -1)
    {
        perror("fcntl");
        close(fd);
        return 1;
    }

    printf("Read lock released.\n");

    close(fd);

    return 0;
}

/*
============================================================================
Commands Used:

gcc read_lock.c -o read_lock
./read_lock

Sample Output / Observation:

Waiting to acquire read lock...
Read lock acquired.
Read lock is held. Press Enter to release it.
Read lock released.
============================================================================
*/
