# Day 19 – Measuring `getpid()` using Time Stamp Counter

## Objective

Find the time taken to execute the `getpid()` system call using the processor's Time Stamp Counter (TSC).

## Program

### `getpid_time.c`

The program reads the TSC immediately before and after calling `getpid()`.

## Important Concepts

### Time Stamp Counter

The Time Stamp Counter is a processor counter that can be read using the x86 `RDTSC` instruction.

The instruction returns a 64-bit value using two 32-bit registers:

* `EAX` – lower 32 bits
* `EDX` – upper 32 bits

The program combines them:

```c
return ((unsigned long long)high << 32) | low;
```

### Measuring `getpid()`

The measurement is performed as:

```c
start = read_tsc();

pid = getpid();

end = read_tsc();

difference = end - start;
```

The difference represents the TSC ticks observed during the interval around `getpid()`.

## Commands Used

```bash
gcc getpid_time.c -o getpid_time
./getpid_time
```

## Sample Output

```text
PID: 12345
TSC before getpid(): 1234567890
TSC after getpid():  1234568120
Time taken by getpid(): 230 cycles
```

The exact values vary between executions.

## Key Learning

The TSC provides a low-level way to measure a very short execution interval. `RDTSC` can be accessed from C using inline assembly.
