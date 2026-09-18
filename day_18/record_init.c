/*
============================================================================
Name        : record_init.c
Author      : Bhumika
Description : Creates three records in a file.
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

    struct record records[3] =
    {
        {1, "Alice"},
        {2, "Bob"},
        {3, "Charlie"}
    };

    // Open/create the file
    fd = open("record.txt", O_RDWR | O_CREAT, 0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    // Write all three records
    if (write(fd, records, sizeof(records)) == -1)
    {
        perror("write");
        close(fd);
        return 1;
    }

    // Close the file
    close(fd);

    printf("Three records created successfully.\n");

    return 0;
}

/*
============================================================================
Commands Used:

gcc record_init.c -o record_init
./record_init

Sample Output / Observation:

Three records created successfully.
============================================================================
*/
