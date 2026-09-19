# Question 25 – Creating Three Child Processes and Using waitpid()

## Objective

Write a C program to create three child processes. The parent process should wait for a particular child using the `waitpid()` system call.

## Program

### 25.c

The program:

1. Creates three child processes using `fork()`.
2. Each child prints its PID and exits after a different delay.
3. The parent stores the PID of each child.
4. The parent specifically waits for Child 2 using `waitpid()`.
5. The exit status of Child 2 is checked and displayed.

## Important Concepts

### 1. Creating Multiple Child Processes

The parent creates three separate child processes:

```text
             Parent
           /    |    \
      Child 1 Child 2 Child 3
````

Each child receives a different PID.

### 2. waitpid()

The `waitpid()` system call allows the parent to wait for a **specific child process**.

```c
waitpid(pid2, &status, 0);
```

Here:

* `pid2` → PID of the child that the parent wants to wait for.
* `&status` → stores the termination status of the child.
* `0` → the parent waits until the specified child terminates.

This is different from `wait()`, which waits for any child that terminates.

### 3. Checking Exit Status

The program uses:

```c
WIFEXITED(status)
```

to check whether the child terminated normally.

Then:

```c
WEXITSTATUS(status)
```

retrieves the exit status returned by the child.

Child 2 exits using:

```c
exit(2);
```

Therefore, its exit status is `2`.

## Commands Used

### Compile

```bash
gcc 25.c -o 25
```

### Run

```bash
./25
```

## Sample Output

Actual output from the experiment:

```text
Parent: PID = 18321
Parent waiting specifically for Child 2: PID = 18323
Child 1: PID = 18322
Child 2: PID = 18323
Child 3: PID = 18324

Child 1 exiting
Child 3 exiting
Child 2 exiting
Child 2 terminated with exit status 2
Parent finished waiting for Child 2
```

Although Child 1 and Child 3 terminated before Child 2, the parent specifically waited for Child 2.

## Verification

The parent waited for:

```text
Child 2: PID = 18323
```

using:

```c
waitpid(pid2, &status, 0);
```

Child 1 and Child 3 exited first, but the parent continued waiting until Child 2 terminated.

The output:

```text
Child 2 terminated with exit status 2
```

confirms that the parent collected Child 2's termination status.

## Key Learning

* A parent can create multiple child processes using `fork()`.
* `waitpid()` allows the parent to wait for a specific child.
* The first argument to `waitpid()` identifies the child process.
* `WIFEXITED()` checks for normal child termination.
* `WEXITSTATUS()` retrieves the child's exit status.
* Other children may terminate while the parent is waiting for a specific child.

````

Create it:

```bash
nano README_25.md
````

Save it.

Then **don't commit yet**. We now have the complete Q22–Q25 batch, so we'll do one final Git review and commit all four together.
