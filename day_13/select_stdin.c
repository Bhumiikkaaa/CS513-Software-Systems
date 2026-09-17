/*
============================================================================
Name        : select_stdin.c
Author      : Bhumika
Description : Waits for input on STDIN for 10 seconds using select().
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>

int main()
{
    fd_set readfds;
    struct timeval timeout;
    int ret;

    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    ret = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &timeout);

    if (ret == -1)
    {
        perror("select");
    }
    else if (ret == 0)
    {
        printf("No data available on STDIN within 10 seconds.\n");
    }
    else
    {
        if (FD_ISSET(STDIN_FILENO, &readfds))
        {
            printf("Data is available on STDIN within 10 seconds.\n");
        }
    }

    return 0;
}

/*
============================================================================
Commands Used:

gcc select_stdin.c -o select_stdin
./select_stdin

Sample Output / Observation:

Case 1: Enter input within 10 seconds
Data is available on STDIN within 10 seconds.

Case 2: Do not enter anything for 10 seconds
No data available on STDIN within 10 seconds.
============================================================================
*/
