/*
============================================================================
Name        : file_info.c
Author      : Bhumika
Description : Print inode, hard links, UID, GID, size, block size,
              number of blocks, and file timestamps using stat().
============================================================================
*/

#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[])
{
    struct stat st;

    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    if (stat(argv[1], &st) == -1)
    {
        perror("stat");
        return 1;
    }

    printf("Inode number      : %lu\n", (unsigned long)st.st_ino);
    printf("Hard links        : %lu\n", (unsigned long)st.st_nlink);
    printf("UID               : %u\n", st.st_uid);
    printf("GID               : %u\n", st.st_gid);
    printf("Size              : %ld bytes\n", (long)st.st_size);
    printf("Block size        : %ld bytes\n", (long)st.st_blksize);
    printf("Blocks            : %ld\n", (long)st.st_blocks);

    printf("Last access       : %s", ctime(&st.st_atime));
    printf("Last modification : %s", ctime(&st.st_mtime));
    printf("Last change       : %s", ctime(&st.st_ctime));

    return 0;
}

/*
============================================================================
Commands Used:
----------------------------------------------------------------------------

Create the source file:
nano file_info.c

Compilation:
gcc file_info.c -o file_info

Execution:
./file_info file1

Execution with another file:
./file_info file2

============================================================================
Sample Output:
----------------------------------------------------------------------------

Inode number      : 1234567
Hard links        : 1
UID               : 1000
GID               : 1000
Size              : 18 bytes
Block size        : 4096 bytes
Blocks            : 8
Last access       : Wed Sep 16 00:00:00 2026
Last modification : Wed Sep 16 00:00:00 2026
Last change       : Wed Sep 16 00:00:00 2026

============================================================================
*/
