/*
============================================================================
Name        : hard_link.c
Author      : Bhumika
Description : Create a hard link using the link() system call.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main()
{
    if (link("hard_link.txt", "hard_link_from_c.txt") == -1)
    {
        perror("Link failed");
        return 1;
    }

    printf("Hard link created successfully\n");

    return 0;
}

/*
============================================================================
Commands Used:
----------------------------------------------------------------------------

Compilation:
gcc hard_link.c -o hard_link

Execution:
./hard_link

Inspect the files:
ls -li hard_link.txt hard_link_from_c.txt

============================================================================
Sample Output / Observation:
----------------------------------------------------------------------------

Hard link created successfully

Both files refer to the same inode.

============================================================================
*/
