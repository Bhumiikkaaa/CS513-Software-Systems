/*
============================================================================
Name        : five_file.c
Author      : Bhumika
Description : Create five files using the creat() system call, keep their
              file descriptors open, and inspect the file descriptor table
              of the running process through /proc/<PID>/fd.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;

    for (int i = 0; i < 5; i++)
    {
        char filename[20];

        sprintf(filename, "file%d", i + 1);

        fd = creat(filename, 0644);

        if (fd == -1)
        {
            perror("creat");
            return 1;
        }

        printf("%s created with file descriptor %d\n", filename, fd);
    }

    while (1)
    {
    }

    return 0;
}

/*
============================================================================
Commands Used:
----------------------------------------------------------------------------

Compilation:
gcc five_file.c -o five_file

Execution in background:
./five_file &

Check the process file descriptor table:
ls -l /proc/<PID>/fd

Terminate the background process:
kill <PID>

============================================================================
Sample Output:
----------------------------------------------------------------------------

file1 created with file descriptor 3
file2 created with file descriptor 4
file3 created with file descriptor 5
file4 created with file descriptor 6
file5 created with file descriptor 7

Example file descriptor table:

0 -> /dev/pts/0
1 -> /dev/pts/0
2 -> /dev/pts/0
3 -> /home/bhumika/CS513-Software-Systems/day_5/file1
4 -> /home/bhumika/CS513-Software-Systems/day_5/file2
5 -> /home/bhumika/CS513-Software-Systems/day_5/file3
6 -> /home/bhumika/CS513-Software-Systems/day_5/file4
7 -> /home/bhumika/CS513-Software-Systems/day_5/file5

============================================================================
*/


	
