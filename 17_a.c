/*
============================================================================
Name        : ticket_init.c
Author      : Bhumika
Description : Initializes the ticket number in a file.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    int ticket = 0;

    // 1. Open/create ticket.txt
    fd = open("ticket.txt",O_RDWR | O_CREAT,0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    // 2. Write the initial ticket number into the file
    if(write(fd,&ticket,sizeof(ticket))==-1)
    {
 	perror("write");
	close(fd);
	return 1;
    }

    // 3. Close the file
    close(fd);

    printf("Ticket number initialized.\n");

    return 0;
}

/*
============================================================================
Commands Used:

gcc ticket_init.c -o ticket_init
./ticket_init

Sample Output / Observation:
Ticket number initialized.
...
============================================================================
*/
