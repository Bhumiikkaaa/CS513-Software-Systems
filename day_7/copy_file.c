/*
============================================================================
Name        : copy_file.c
Author      : Bhumika
Description : Copy the contents of file1 into file2 using open(), read(),
              write(), and close() system calls.
============================================================================
*/

#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd1, fd2, n;
    char buffer[100];

    fd1 = open("file1", O_RDONLY);

    if (fd1 == -1)
    {
        return 1;
    }

    fd2 = open("file2", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd2 == -1)
    {
        close(fd1);
        return 1;
    }

    while ((n = read(fd1, buffer, sizeof(buffer))) > 0)
    {
        write(fd2, buffer, n);
    }

    close(fd1);
    close(fd2);

    return 0;
}

/*
============================================================================
Commands Used:
----------------------------------------------------------------------------

Create source file:
echo "Hello Bhumika! This is file1." > file1

Compilation:
gcc copy_file.c -o copy_file

Execution:
./copy_file

Display contents:
cat file1
cat file2

Compare files:
cmp file1 file2

============================================================================
Sample Output:
----------------------------------------------------------------------------

$ cat file1
Hello Bhumika! This is file1.

$ cat file2
Hello Bhumika! This is file1.

$ cmp file1 file2

============================================================================
*/

