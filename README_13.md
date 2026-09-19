# Day 13 – `select()` System Call

## Objective

Write a program that waits for data on STDIN for 10 seconds using the `select()` system call.

## Program

### `select_stdin.c`

The program monitors STDIN (`file descriptor 0`) using `select()`.

It waits for a maximum of 10 seconds and prints whether data became available within that time.

## Important Concepts

### `select()`

`select()` monitors file descriptors and waits until one or more become ready for I/O, or until the specified timeout expires.

### `fd_set`

`fd_set` stores the set of file descriptors that `select()` should monitor.

The program uses:

* `FD_ZERO()` to clear the set.
* `FD_SET()` to add STDIN to the set.
* `FD_ISSET()` to check whether STDIN became ready.

### `struct timeval`

The timeout is specified using `struct timeval`.

```text
tv_sec  = seconds
tv_usec = microseconds
```

The program sets the timeout to 10 seconds.

### Return Value of `select()`

```text
> 0  → one or more file descriptors are ready
  0  → timeout occurred
< 0  → error
```

## Commands Used

```bash
gcc select_stdin.c -o select_stdin
./select_stdin
```

## Sample Output

### Data entered within 10 seconds

```text
Data is available on STDIN within 10 seconds.
```

### No data entered within 10 seconds

```text
No data available on STDIN within 10 seconds.
```

## Verification

The program was tested by:

1. Running the program and entering input within 10 seconds.
2. Running the program again without entering input until the 10-second timeout expired.

The program correctly reported whether STDIN became ready within the specified timeout.

## Key Learning

`select()` can be used to wait for file descriptors to become ready without waiting indefinitely. It detects whether STDIN is ready for reading, but it does not itself read or consume the input.
