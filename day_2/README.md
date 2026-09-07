# Day 2: Process Information Using `/proc`

## Objective

To write a simple program that executes in an infinite loop in the background and explore the process-related information available in the corresponding `/proc/<PID>` directory.

---

## Program

### `infinite_loop.c`

```c
#include <stdio.h>

int main()
{
    while (1)
    {
    }

    return 0;
}
```

The `while(1)` loop runs indefinitely, causing the program to continuously execute until it is manually terminated or the system shuts down.

---

## Compilation

The program was compiled using:

```bash
gcc infinite_loop.c -o infinite_loop
```

Here:

* `gcc` is the GNU C compiler.
* `infinite_loop.c` is the source file.
* `-o infinite_loop` specifies the name of the output executable.

---

## Running the Program in the Background

The program was executed using:

```bash
./infinite_loop &
```

The `&` symbol runs the process in the background, allowing the terminal to remain available for other commands.

Example output:

```text
[1] 22433
```

Where:

* `[1]` is the shell job number.
* `22433` is the Process ID (PID).

---

## Checking the Process

The process was verified using:

```bash
ps -p 22433
```

CPU and memory usage were checked using:

```bash
ps -p 22433 -o pid,stat,%cpu,%mem,cmd
```

Observation:

```text
PID    STAT   %CPU   %MEM   CMD
22433  R      ~100   ~0.0   ./infinite_loop
```

The process consumed approximately 100% of one CPU core because the infinite loop continuously executes without sleeping or waiting.

Therefore, the process is CPU-bound.

---

# Exploring `/proc/<PID>`

For a process with PID `22433`, process-related information is available in:

```text
/proc/22433/
```

The contents can be viewed using:

```bash
ls /proc/22433
```

The `/proc` filesystem is a virtual filesystem that provides information maintained by the Linux kernel about running processes and the system.

---

## Important Process Information Explored

### 1. `status`

Command:

```bash
cat /proc/22433/status
```

Provides human-readable information about the process, including:

* Process name
* Process state
* PID
* Parent PID
* Memory usage
* Number of threads

Example:

```text
Name: infinite_loop
State: R (running)
Threads: 1
```

---

### 2. `stat`

Command:

```bash
cat /proc/22433/stat
```

Provides detailed process statistics in a compact, fixed-order format.

It includes information such as:

* PID
* Process name
* Process state
* Parent PID
* CPU statistics
* Priority
* Number of threads
* Memory information

---

### 3. `statm`

Command:

```bash
cat /proc/22433/statm
```

Provides memory usage information in memory pages.

Important fields include:

* Total program size
* Resident memory
* Shared memory
* Text/code memory
* Data and stack memory

---

### 4. `cmdline`

Command:

```bash
tr '\0' ' ' < /proc/22433/cmdline
```

Shows the command-line arguments used to start the process.

Null characters are converted into spaces to make the output readable.

---

### 5. `comm`

Command:

```bash
cat /proc/22433/comm
```

Displays the name of the process.

Example:

```text
infinite_loop
```

---

### 6. `cwd`

Command:

```bash
ls -l /proc/22433/cwd
```

Displays the Current Working Directory of the process.

---

### 7. `exe`

Command:

```bash
ls -l /proc/22433/exe
```

Displays the path to the executable currently being executed by the process.

Example:

```text
/home/bhumika/CS513-Software-Systems/day_2/infinite_loop
```

---

### 8. `fd`

Command:

```bash
ls -l /proc/22433/fd
```

Displays the open file descriptors of the process.

The standard file descriptors are:

* `0` → Standard Input (stdin)
* `1` → Standard Output (stdout)
* `2` → Standard Error (stderr)

---

### 9. `io`

Command:

```bash
cat /proc/22433/io
```

Provides I/O statistics for the process, including:

* Bytes read
* Bytes written
* Number of read system calls
* Number of write system calls

Since the infinite-loop program performs almost no I/O operations, its I/O activity is minimal.

---

### 10. `limits`

Command:

```bash
cat /proc/22433/limits
```

Displays resource limits for the process.

Examples include:

* Maximum CPU time
* Maximum number of open files
* Maximum number of processes
* Maximum stack size

It also displays soft and hard limits.

---

### 11. `task`

Command:

```bash
ls /proc/22433/task
```

Displays the threads belonging to the process.

The program had:

```text
Threads: 1
```

Therefore, only one Thread ID was present.

For this single-threaded process:

```text
PID = TID
```

---

### 12. `sched`

Command:

```bash
cat /proc/22433/sched
```

Provides CPU scheduling information, including:

* Execution runtime
* Number of context switches
* Voluntary context switches
* Involuntary context switches
* Scheduling priority

The infinite-loop process had many involuntary context switches because it continuously wanted CPU time and the operating system scheduler periodically allocated CPU time to other processes.

---

### 13. `schedstat`

Command:

```bash
cat /proc/22433/schedstat
```

Provides compact scheduling statistics related to:

* Time spent executing
* Time spent waiting
* Number of times the process was scheduled

---

### 14. `maps`

Command:

```bash
cat /proc/22433/maps
```

Displays the virtual memory regions mapped into the process.

The output included:

* The `infinite_loop` executable
* `libc.so.6`
* Dynamic loader
* Stack
* Kernel-provided memory regions

Example permissions:

```text
r-xp
```

means:

* `r` → Read permission
* `x` → Execute permission
* `p` → Private mapping

Program code is generally mapped with execute permission.

```text
rw-p
```

represents a region with read and write permissions.

---

### 15. `environ`

Command:

```bash
cat /proc/22433/environ | tr '\0' '\n'
```

Displays the environment variables inherited by the process.

Examples included:

```text
HOME=/home/bhumika
USER=bhumika
PWD=/home/bhumika/CS513-Software-Systems/day_2
SHELL=/bin/bash
PATH=...
```

The process inherits its environment variables from the environment in which it was started.

---

# Program vs Process

A program is a file stored on disk.

```text
infinite_loop.c → Source code
infinite_loop   → Executable
```

When the executable is run:

```bash
./infinite_loop
```

Linux creates a running process and assigns it a PID.

```text
Executable
    ↓
Process created
    ↓
PID assigned
    ↓
/proc/<PID>/ contains runtime information
```

When the process terminates:

* `/proc/<PID>/` disappears.
* The source code remains on disk.
* The executable remains on disk.

Running the executable again creates a new process, usually with a new PID.

---

# Background Process

Running:

```bash
./infinite_loop &
```

starts the process in the background.

Without `&`:

```bash
./infinite_loop
```

the terminal would remain occupied because the program never terminates.

The `&` symbol allows the shell to return the terminal prompt immediately while the process continues running.

---

# Observation During System Sleep

The system was put into sleep mode while the process was running.

After waking the system, the process was still present:

```bash
ps -p <PID>
```

The process remained alive and resumed execution after the system woke up.

This differs from shutting down the system, where running processes are terminated.

---

# Key Learnings

1. A program and a process are different.
2. Every running process has a Process ID (PID).
3. Linux provides process-related runtime information through `/proc/<PID>/`.
4. The `&` operator runs a process in the background.
5. The infinite-loop program is CPU-bound and consumed approximately 100% of one CPU core.
6. `/proc/<PID>/status` provides human-readable process information.
7. `/proc/<PID>/fd` shows open file descriptors.
8. `/proc/<PID>/task` provides thread-related information.
9. `/proc/<PID>/maps` shows virtual memory mappings.
10. `/proc/<PID>/environ` shows environment variables inherited by the process.
11. Process information in `/proc/<PID>/` exists only while the process exists.
