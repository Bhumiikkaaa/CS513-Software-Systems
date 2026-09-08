/*
============================================================================
Name        : soft_link.c
Author      : Bhumika
Description : Create a symbolic link using the symlink() system call.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main()
{
    if (symlink("hard_link.txt", "soft_link_from_c.txt") == -1)
    {
        perror("symlink failed");
        return 1;
    }

    printf("Soft link created successfully!\n");

    return 0;
}

/*
============================================================================
Commands Used:
----------------------------------------------------------------------------

Compilation:
gcc soft_link.c -o soft_link

Execution:
./soft_link

Inspect the symbolic link:
ls -l soft_link_from_c.txt

============================================================================
Sample Output / Observation:
----------------------------------------------------------------------------

Soft link created successfully!

The symbolic link points to:

soft_link_from_c.txt -> hard_link.txt

============================================================================
*/
