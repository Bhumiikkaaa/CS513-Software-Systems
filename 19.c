/*
============================================================================
Name        : getpid_time.c
Author      : Bhumika
Description : Measures the time taken to execute getpid() using the
              Time Stamp Counter (TSC).
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

unsigned long long read_tsc()
{
    unsigned int low, high;

    __asm__ volatile (
        "rdtsc"
        : "=a"(low), "=d"(high)
    );

    return ((unsigned long long)high << 32) | low;
}

int main()
{
    unsigned long long start, end, difference;
    pid_t pid;

    start = read_tsc();

    pid = getpid();

    end = read_tsc();

    difference = end - start;

    printf("PID: %d\n", pid);
    printf("TSC before getpid(): %llu\n", start);
    printf("TSC after getpid():  %llu\n", end);
    printf("Time taken by getpid(): %llu cycles\n", difference);

    return 0;
}

/*
============================================================================
Commands Used:

gcc getpid_time.c -o getpid_time
./getpid_time

Sample Output / Observation:

PID: 12345
TSC before getpid(): 1234567890
TSC after getpid():  1234568120
Time taken by getpid(): 230 cycles
============================================================================
*/
