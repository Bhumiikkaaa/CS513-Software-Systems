/*
============================================================================
Name        : record_lock.c
Author      : Bhumika
Description : Demonstrates record locking using fcntl().
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

struct record
{
    int id;
    char name[20];
};

int main()
{
    int fd;
    int record_no;
    struct record record;
    struct flock lock;

    // Open the record file
    fd = open("record.txt", O_RDWR | O_CREAT, 0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    // Ask which record to access
    printf("Enter record number (1-3): ");
    scanf("%d", &record_no);

    if (record_no < 1 || record_no > 3)
    {
        printf("Invalid record number.\n");
        close(fd);
        return 1;
    }

    // Set up write lock for the selected record
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = (record_no - 1) * sizeof(struct record);
    lock.l_len = sizeof(struct record);

    printf("Waiting to acquire lock for record %d...\n", record_no);

    // Acquire the lock
    if (fcntl(fd, F_SETLKW, &lock) == -1)
    {
        perror("fcntl");
        close(fd);
        return 1;
    }

    printf("Record %d locked.\n", record_no);

    // Move to the selected record
    if (lseek(fd, lock.l_start, SEEK_SET) == -1)
    {
        perror("lseek");
        close(fd);
        return 1;
    }

    // Read the selected record
    if (read(fd, &record, sizeof(record)) == -1)
    {
        perror("read");
        close(fd);
        return 1;
    }

    printf("ID: %d\n", record.id);
    printf("Name: %s\n", record.name);

    // Hold the lock so that locking can be observed
    printf("Record is locked. Press Enter to release it.\n");
    getchar();
    getchar();

    // Unlock the record
    lock.l_type = F_UNLCK;

    if (fcntl(fd, F_SETLK, &lock) == -1)
    {
        perror("fcntl");
        close(fd);
        return 1;
    }

    printf("Record %d unlocked.\n", record_no);

    close(fd);

    return 0;
}

/*
============================================================================
Commands Used:

gcc record_lock.c -o record_lock
./record_lock

Sample Output / Observation:

Enter record number (1-3): 2
Waiting to acquire lock for record 2...
Record 2 locked.
ID: 2
Name: Bob
Record is locked. Press Enter to release it.
Record 2 unlocked.
============================================================================
*/
