# Day 16 – File Locking using `fcntl()`

## Objective

Write programs to demonstrate file locking using `fcntl()`:

1. Implement a write lock.
2. Implement a read lock.

## Programs

### `write_lock.c`

Demonstrates acquiring and releasing a write lock on a file.

### Read Lock Program

Demonstrates acquiring and releasing a read lock on a file.

## Important Concepts

### `struct flock`

`struct flock` describes the lock:

```c
struct flock lock;
```

Important members:

* `l_type` – type of lock (`F_RDLCK`, `F_WRLCK`, `F_UNLCK`)
* `l_whence` – starting point for the lock
* `l_start` – starting byte
* `l_len` – number of bytes to lock

For a whole-file lock:

```c
lock.l_whence = SEEK_SET;
lock.l_start = 0;
lock.l_len = 0;
```

`l_len = 0` means the lock extends from the starting position to the end of the file.

### Write Lock

```c
lock.l_type = F_WRLCK;
```

A write lock conflicts with both read and write locks.

### Read Lock

```c
lock.l_type = F_RDLCK;
```

Multiple read locks can coexist, but a read lock conflicts with a write lock.

### `F_SETLKW`

```c
fcntl(fd, F_SETLKW, &lock);
```

Requests the lock and waits if the lock is currently unavailable.

### `F_SETLK`

```c
fcntl(fd, F_SETLK, &lock);
```

Requests the lock without waiting.

## Commands Used

```bash
gcc write_lock.c -o write_lock
./write_lock
```

Compile and run the read-lock program similarly.

To demonstrate locking, run the same program from two terminals.

## Sample Observation

### Write Lock

Terminal 1:

```text
Waiting to acquire write lock...
Write lock acquired.
Lock is held. Press Enter to release it.
```

Terminal 2 waits until Terminal 1 releases the lock.

### Read Lock

Multiple processes can acquire read locks at the same time.

A read lock and a write lock cannot be held simultaneously on the same region.

## Key Learning

`fcntl()` can be used to coordinate access to a file. Locks can be applied to a whole file or to a specific byte range.
