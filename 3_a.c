/*
============================================================================
Name        : creat_file.c
Author      : Bhumika
Description : Create a file using the creat() system call and print the
              file descriptor returned by the system call.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;

    fd = creat("newfile.txt", 0644);

    if (fd == -1)
    {
        perror("creat");
        return 1;
    }

    printf("File created successfully.\n");
    printf("File descriptor value: %d\n", fd);

    close(fd);

    return 0;
}

/*
============================================================================
Commands Used:
----------------------------------------------------------------------------

Compilation:
gcc creat_file.c -o creat_file

Execution:
./creat_file

Inspect the created file:
ls -l newfile.txt

============================================================================
Sample Output:
----------------------------------------------------------------------------

File created successfully.
File descriptor value: 3

Example file information:

-rw-r--r-- 1 bhumika bhumika 0 ... newfile.txt

============================================================================
*/
