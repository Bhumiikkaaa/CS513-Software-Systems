# Question 21 – Parent and Child Process IDs using fork()

## Objective

Write a C program to call `fork()` and print the parent and child process IDs.

## Program

### 21.c

The program creates a child process using `fork()` and prints:

- Parent process ID
- Child process ID
- Parent PID from the child's perspective

## Important Concepts

### 1. fork()

`fork()` creates a new process called the child process.

After `fork()` successfully executes, both the parent and child continue execution from the statement immediately after `fork()`.

### 2. Return value of fork()

The return value of `fork()` is different in the parent and child:

| Process | Return value |
|---|---|
| Parent | Child's PID |
| Child | 0 |
| Error | -1 |

Therefore:

```c
if (pid < 0)
````

means `fork()` failed.

```c
else if (pid == 0)
```

means the code is executing in the child.

```c
else
```

means the code is executing in the parent.

### 3. getpid()

```c
getpid()
```

returns the process ID of the current process.

### 4. getppid()

```c
getppid()
```

returns the process ID of the current process's parent.

## Commands Used

### Compile

```bash
gcc 21.c -o 21
```

### Run

```bash
./21
```

## Sample Output

```text
Parent Process
Parent PID : 14843
Child PID  : 14844
Child Process
Child PID  : 14844
Parent PID : 2028
```

The parent process received the child's PID (`14844`) as the return value of `fork()`.

The child process received `0` as the return value of `fork()`.

In this execution, the original parent process terminated before the child called `getppid()`. Therefore, the child's `getppid()` returned `2028`, showing that the child's parent can change if the original parent terminates.

## Verification

For a successful `fork()`:

```text
Parent: fork() returns child PID
Child : fork() returns 0
```

The parent can obtain the child's PID from the return value of `fork()`.

The child can obtain its own PID using `getpid()` and its parent's PID using `getppid()`.

## Key Learning

* `fork()` creates a new child process.
* After `fork()`, both parent and child continue execution.
* The parent receives the child's PID from `fork()`.
* The child receives `0` from `fork()`.
* `getpid()` returns the current process ID.
* `getppid()` returns the current parent process ID.
* Parent and child execution order is not guaranteed.
