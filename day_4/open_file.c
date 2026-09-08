/*
============================================================================
Name        : open_file.c
Author      : Bhumika
Description : Open an existing file in read-write mode using the open()
              system call and print the file descriptor.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
	int fd;
	fd = open("existing_file.txt",O_RDWR);
	if(fd == -1){
		perror("opening");
		return 1;
	}
	printf("File opened succesfully");
	printf("File descriptor value: %d\n", fd);
	close(fd);
	return 0;
}

/*
============================================================================
Commands Used:
----------------------------------------------------------------------------

Create the existing file:
touch existing_file.txt

Compilation:
gcc open_file.c -o open_file

Execution:
./open_file

Check the file:
ls -l existing_file.txt

============================================================================
Sample Output / Observation:
----------------------------------------------------------------------------

File opened successfully
File descriptor value: 3

The file descriptor is 3 because:

0 -> Standard Input
1 -> Standard Output
2 -> Standard Error

Therefore, 3 is the lowest available file descriptor.

The file remains empty because the program only opens and closes the file.
No read() or write() operation is performed.

============================================================================
*/
