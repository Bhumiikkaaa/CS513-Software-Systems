/*
============================================================================
Name        : 30.c
Author      : Bhumika
Description : Run a shell script at a specific time using a daemon process.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>

int main(int argc, char *argv[])
{
    pid_t pid;
    time_t now;
    struct tm *current_time;
    int target_hour;
    int target_minute;
    char script_path[PATH_MAX];
    char command[PATH_MAX + 10];

    if (argc != 4)
    {
        printf("Usage: %s <hour> <minute> <script>\n", argv[0]);
        return EXIT_FAILURE;
    }

    target_hour = atoi(argv[1]);
    target_minute = atoi(argv[2]);

    if (realpath(argv[3], script_path) == NULL)
    {
        perror("realpath");
        return EXIT_FAILURE;
    }

    pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return EXIT_FAILURE;
    }

    if (pid > 0)
    {
        printf("Daemon started with PID: %d\n", pid);
        return 0;
    }

    if (setsid() == -1)
    {
        perror("setsid");
        exit(EXIT_FAILURE);
    }

    chdir("/");
    umask(0);

    while (1)
    {
        now = time(NULL);
        current_time = localtime(&now);

        if (current_time->tm_hour == target_hour &&
            current_time->tm_min == target_minute)
        {
            break;
        }

        sleep(1);
    }

    snprintf(command, sizeof(command), "sh %s", script_path);
    system(command);

    return 0;
}

/*
============================================================================
Commands Used:

gcc 30.c -o 30
./30 <hour> <minute> <script>

Example:

./30 21 55 test.sh

Sample Output / Observation:

Daemon started with PID: 12345

After the specified time:

Script executed at Sat Sep 19 21:55:00 PM IST 2026
============================================================================
*/
