/*
============================================================================
Name        : dup_file.c
Author      : Bhumika
Description : Open a file in read-write append mode, duplicate the file
              descriptor using dup(), and append data using both descriptors.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd1, fd2;

    fd1 = open("file1", O_RDWR | O_CREAT | O_APPEND, 0644);

    if (fd1 == -1)
    {
        perror("open");
        return 1;
    }

    fd2 = dup(fd1);

    if (fd2 == -1)
    {
        perror("dup");
        close(fd1);
        return 1;
    }

    printf("Original FD : %d\n", fd1);
    printf("Duplicate FD: %d\n", fd2);

    write(fd1, "ABCDEFGHIJ", 10);
    write(fd2, "1234567890", 10);

    close(fd1);
    close(fd2);

    return 0;
}

/*
============================================================================
Commands Used:
----------------------------------------------------------------------------

Create the source file:
nano dup_file.c

Compilation:
gcc dup_file.c -o dup_file

Execution:
./dup_file

Check file contents:
cat file1

Check file contents byte by byte:
od -c file1

============================================================================
Sample Output:
----------------------------------------------------------------------------

Original FD : 3
Duplicate FD: 4

============================================================================
*/
