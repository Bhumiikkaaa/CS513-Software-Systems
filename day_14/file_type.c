/*
============================================================================
Name        : file_type.c
Author      : Bhumika
Description : Identifies the type of a file using lstat().
============================================================================
*/

#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    struct stat file_info;

    if (argc != 2)
    {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    if (lstat(argv[1], &file_info) == -1)
    {
        perror("lstat");
        return 1;
    }

    if (S_ISREG(file_info.st_mode))
        printf("%s is a regular file.\n", argv[1]);
    else if (S_ISDIR(file_info.st_mode))
        printf("%s is a directory.\n", argv[1]);
    else if (S_ISLNK(file_info.st_mode))
        printf("%s is a symbolic link.\n", argv[1]);
    else if (S_ISFIFO(file_info.st_mode))
        printf("%s is a FIFO (named pipe).\n", argv[1]);
    else if (S_ISCHR(file_info.st_mode))
        printf("%s is a character device.\n", argv[1]);
    else if (S_ISBLK(file_info.st_mode))
        printf("%s is a block device.\n", argv[1]);
    else if (S_ISSOCK(file_info.st_mode))
        printf("%s is a socket.\n", argv[1]);
    else
        printf("%s is of an unknown file type.\n", argv[1]);

    return 0;
}

/*
============================================================================
Commands Used:

gcc file_type.c -o file_type
./file_type <file_path>

Sample Output / Observation:

./file_type file1
file1 is a regular file.

./file_type .
. is a directory.
============================================================================
*/
