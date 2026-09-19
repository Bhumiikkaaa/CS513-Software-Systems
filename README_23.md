````markdown
# Question 23 – Creating a Zombie Process

## Objective

Write a C program to create a zombie state of the running program and verify the zombie process using the `ps` command.

## Program

### 23.c

The program:

1. Creates a child process using `fork()`.
2. The child process terminates using `exit()`.
3. The parent process does not call `wait()`.
4. The parent remains alive for 60 seconds.
5. During this time, the terminated child remains in the process table as a zombie.

## Important Concepts

### 1. Zombie Process

A zombie process is a child process that has finished execution but whose parent has not yet collected its exit status using `wait()` or `waitpid()`.

The child is no longer executing, but its process-table entry remains temporarily.

### 2. Creating the Zombie

The child exits:

```c
exit(0);
````

while the parent does not call:

```c
wait();
```

The parent instead remains alive using:

```c
sleep(60);
```

This gives us time to observe the child in the zombie state.

### 3. Process State

The `ps` command was used to inspect the child:

```bash
ps -o pid,ppid,state,comm -p <child_pid>
```

The `state` column shows the current process state.

`Z` means that the process is a **zombie**.

## Commands Used

### Compile

```bash
gcc 23.c -o 23
```

### Run

```bash
./23
```

### Check the Child Process

In another terminal:

```bash
ps -o pid,ppid,state,comm -p <child_pid>
```

## Sample Output

The child process was observed using:

```bash
ps -o pid,ppid,state,comm -p 17791
```

Output:

```text
    PID    PPID S COMMAND
  17791   17790 Z 23
```

Here:

* `PID 17791` → child process ID.
* `PPID 17790` → parent process ID.
* `Z` → zombie process state.
* `23` → program name.

## Verification

The output shows:

```text
S = Z
```

which confirms that the child process was in the zombie state.

The child had already terminated, but its entry remained because the parent had not called `wait()` to collect its exit status.

## Key Learning

* A zombie process has completed execution but remains in the process table.
* A parent can create a zombie by not calling `wait()` or `waitpid()` after the child terminates.
* The `ps` command can be used to inspect process states.
* `Z` in the process state indicates a zombie process.
* The zombie exists only while its parent has not collected its termination status.

````

Create it:

```bash
nano README_23.md
````

Save it.

**Don't stage yet** — we'll continue with Question 24 and keep Questions **22–25 as one commit**, as planned.
