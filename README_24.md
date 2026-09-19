# Question 24 – Creating an Orphan Process

## Objective

Write a C program to create an orphan process and observe the change in the child's parent process ID.

## Program

### 24.c

The program:

1. Creates a child process using `fork()`.
2. The child prints its PID and its initial parent PID.
3. The parent waits for 2 seconds and then exits.
4. The child continues running after the parent exits.
5. The child prints its new parent PID.

## Important Concepts

### 1. Orphan Process

An orphan process is a child process whose parent process has terminated while the child is still running.

In this program, the parent exits before the child:

```text
Parent
  |
 fork()
 /    \
Parent Child
  |
exit()
       |
       | continues running
       ↓
    Orphan
````

### 2. getppid()

```c
getppid()
```

returns the process ID of the current process's parent.

The child first records the original parent's PID:

```c
printf("Initial Parent PID : %d\n", getppid());
```

After the original parent exits, the child calls `getppid()` again and observes its new parent.

### 3. Reparenting

When the original parent terminates while the child is still running, the child is reparented to another process.

Therefore, the child's `PPID` changes.

## Commands Used

### Compile

```bash
gcc 24.c -o 24
```

### Run

```bash
./24
```

## Sample Output

Actual output from the experiment:

```text
Parent Process
Parent PID : 18047
Child PID  : 18048
Child Process
Child PID  : 18048
Initial Parent PID : 18047
Parent is exiting...

After Parent Exits
Child PID  : 18048
New Parent PID : 2028
```

The original parent process was `18047`.

After the parent exited, the child process `18048` continued running and its new parent PID became `2028`.

## Verification

Before the parent exits:

```text
Child PID        : 18048
Parent PID       : 18047
```

After the parent exits:

```text
Child PID        : 18048
New Parent PID   : 2028
```

The child continued running even though its original parent terminated. This confirms that the child became an orphan and was reparented.

## Key Learning

* An orphan process is a child whose parent has terminated while the child is still running.
* `getppid()` returns the PID of the current parent.
* When the original parent terminates, the child is reparented.
* The child continues execution after its original parent exits.
* The child's parent PID can therefore change during its lifetime.

````

Create it:

```bash
nano README_24.md
````

Save it. **Don't stage yet**—we still have Q25 to complete before the combined **Q22–Q25 commit**.
