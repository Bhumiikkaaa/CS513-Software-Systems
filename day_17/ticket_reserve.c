/*
============================================================================
Name        : ticket_reserve.c
Author      : Bhumika
Description : Reserves a ticket using a write lock.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    int ticket;
    struct flock lock;

    // Open the ticket file
    fd = open("ticket.txt", O_RDWR | O_CREAT, 0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    // Set up write lock for the whole file
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    printf("Waiting to acquire write lock...\n");

    // Acquire lock and wait if another process holds it
    if (fcntl(fd, F_SETLKW, &lock) == -1)
    {
        perror("fcntl");
        close(fd);
        return 1;
    }

    printf("Write lock acquired.\n");
    sleep(10);

    // Read current ticket number
    if (read(fd, &ticket, sizeof(ticket)) == -1)
    {
        perror("read");
        close(fd);
        return 1;
    }

    // Increment ticket number
    ticket++;

    // Move back to beginning of file
    lseek(fd, 0, SEEK_SET);

    // Write updated ticket number
    if (write(fd, &ticket, sizeof(ticket)) == -1)
    {
        perror("write");
        close(fd);
        return 1;
    }

    printf("New ticket number: %d\n", ticket);

    // Release the lock
    lock.l_type = F_UNLCK;

    if (fcntl(fd, F_SETLK, &lock) == -1)
    {
        perror("fcntl");
    }

    printf("Write lock released.\n");

    // Close the file
    close(fd);

    return 0;
}

/*
============================================================================
Commands Used:

gcc ticket_reserve.c -o ticket_reserve
./ticket_reserve

Sample Output / Observation:

Waiting to acquire write lock...
Write lock acquired.
New ticket number: 1
Write lock released.
============================================================================
*/
