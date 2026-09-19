/*
============================================================================
Name        : excl_experiment.c
Author      : Bhumika
Description : Demonstrate the O_CREAT and O_EXCL flags using the open()
              system call.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;

    fd = open("existing.txt", O_RDWR | O_CREAT | O_EXCL, 0644);

    if (fd == -1)
    {
        perror("excl");
        return 1;
    }

    printf("File opened successfully using O_EXCL\n");
    printf("File descriptor value: %d\n", fd);

    close(fd);

    return 0;
}

/*
============================================================================
Commands Used:
----------------------------------------------------------------------------

Compilation:
gcc excl_experiment.c -o excl_experiment

First execution:
./excl_experiment

Check the created file:
ls -l existing.txt

Second execution:
./excl_experiment

============================================================================
Sample Output / Observation:
----------------------------------------------------------------------------

First execution:

File opened successfully using O_EXCL
File descriptor value: 3

The file existing.txt is created because it did not exist.

Second execution:

excl: File exists

The second execution fails because existing.txt already exists.

O_CREAT creates the file if it does not exist.

O_EXCL, when used with O_CREAT, causes open() to fail if the file
already exists.

============================================================================
*/
