# Day 20 – Process Priority and Nice Value

## Objective

Find the priority of a running program and modify its priority using the `nice` command.

## Program

### `priority.c`

Displays the PID of the running program so that its scheduling information can be inspected using `ps`.

## Important Concepts

### Process ID

The program obtains its PID using:

```c
getpid()
```

### Nice Value

The nice value (`NI`) affects the scheduling priority of a process.

The default nice value is:

```text
NI = 0
```

A higher nice value makes the process more willing to yield CPU time to other processes.

### `ps`

The following command displays the process information:

```bash
ps -o pid,ni,pri,comm -p <PID>
```

The columns are:

* `PID` – process ID
* `NI` – nice value
* `PRI` – priority
* `COMMAND` – program name

### `nice`

A program can be started with a modified nice value:

```bash
nice -n 5 ./priority
```

This starts the program with a nice value of `5`.

## Commands Used

Compile:

```bash
gcc priority.c -o priority
```

Run normally:

```bash
./priority
```

Check priority:

```bash
ps -o pid,ni,pri,comm -p <PID>
```

Run with a nice value of 5:

```bash
nice -n 5 ./priority
```

Check again:

```bash
ps -o pid,ni,pri,comm -p <PID>
```

## Sample Observation

Normal execution:

```text
PID    NI   PRI   COMMAND
6146    0   19    priority
```

Execution with:

```bash
nice -n 5 ./priority
```

produced a nice value of:

```text
NI = 5
```

## Key Learning

The `nice` value can be used to adjust the scheduling priority of a process. The `ps` command allows the PID, nice value, priority, and command name to be inspected.
