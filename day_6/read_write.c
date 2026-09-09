/*
============================================================================
Name        : read_write.c
Author      : Bhumika
Description : Take input from standard input using the read() system call
              and display it on standard output using the write() system call.
============================================================================
*/

#include <unistd.h>

int main()
{
    char buffer[100];
    int n;

    n = read(0, buffer, sizeof(buffer));

    if (n == -1)
    {
        return 1;
    }

    write(1, buffer, n);

    return 0;
}

/*
============================================================================
Commands Used:
----------------------------------------------------------------------------

Compilation:
gcc read_write.c -o read_write

Execution:
./read_write

============================================================================
Sample Output:
----------------------------------------------------------------------------

Hello World
Hello World

============================================================================
*/
