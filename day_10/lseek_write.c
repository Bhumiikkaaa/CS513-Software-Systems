/*
============================================================================
Name        : lseek_write.c
Author      : Bhumika
Description : Open a file in read-write mode, write 10 bytes, move the file
              pointer forward by 10 bytes using lseek(), and write another
              10 bytes.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    off_t position;
    char data1[] = "ABCDEFGHIJ";
    char data2[] = "KLMNOPQRST";

    fd = open("file1", O_RDWR | O_CREAT | O_TRUNC, 0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    write(fd, data1, 10);

    position = lseek(fd, 10, SEEK_CUR);

    if (position == -1)
    {
        perror("lseek");
        close(fd);
        return 1;
    }

    printf("New file position: %ld\n", (long)position);

    write(fd, data2, 10);

    close(fd);

    return 0;
}

/*
============================================================================
Commands Used:
----------------------------------------------------------------------------

Create the source file:
nano lseek_write.c

Compilation:
gcc lseek_write.c -o lseek_write

Execution:
./lseek_write

Check file contents:
cat file1

Check file contents byte by byte:
od -c file1

Check file size:
ls -l file1

============================================================================
Sample Output:
----------------------------------------------------------------------------

New file position: 20

============================================================================
*/
