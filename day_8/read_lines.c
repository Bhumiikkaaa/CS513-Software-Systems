/*
============================================================================
Name        : read_lines.c
Author      : Bhumika
Description : Open a file in read-only mode, read it one character at a
              time, display each line as it is read, and close the file
              when end of file is reached.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    char ch;

    fd = open("file1", O_RDONLY);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    while (read(fd, &ch, 1) > 0)
    {
        write(1, &ch, 1);
    }

    close(fd);

    return 0;
}

/*
============================================================================
Commands Used:
----------------------------------------------------------------------------

Create the source file:
nano read_lines.c

Compilation:
gcc read_lines.c -o read_lines

Create sample input file:
nano file1

Example contents of file1:
Hello
This is CS513
Software Systems

Execution:
./read_lines

Check the contents of the file:
cat file1

============================================================================
Sample Output:
----------------------------------------------------------------------------

Hello
This is CS513
Software Systems

============================================================================
*/
