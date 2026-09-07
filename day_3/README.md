# Day 3 – File Creation Using `creat()` System Call

## Objective

To understand the `creat()` system call in Linux by:

* Creating a file using a C program.
* Printing the file descriptor returned by `creat()`.
* Understanding standard file descriptors.
* Understanding the importance of `close()`.
* Performing an experiment to observe file descriptor allocation and reuse.

---

## Question

Write a program to create a file and print the file descriptor value using the `creat()` system call.

---

# 1. Creating a File Using `creat()`

## Program: `creat_file.c`

```c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;

    fd = creat("newfile.txt", 0644);

    if (fd == -1)
    {
        perror("creat");
        return 1;
    }

    printf("File created successfully.\n");
    printf("File descriptor value: %d\n", fd);

    close(fd);

    return 0;
}
```

---

## Compilation

```bash
gcc creat_file.c -o creat_file
```

## Execution

```bash
./creat_file
```

### Output

```text
File created successfully.
File descriptor value: 3
```

The file was successfully created:

```bash
ls -l newfile.txt
```

Output:

```text
-rw-r--r-- 1 bhumika bhumika 0 newfile.txt
```

---

# Understanding `creat()`

The `creat()` system call is used to create a file.

Syntax:

```c
int creat(const char *pathname, mode_t mode);
```

Example:

```c
creat("newfile.txt", 0644);
```

### Parameters

* `pathname` → Name or path of the file to create.
* `mode` → Permissions assigned to the file.

The permission `0644` means:

```text
Owner  → Read + Write
Group  → Read
Others → Read
```

---

# File Descriptor

A file descriptor is a non-negative integer used by a process to access an open file or other input/output resource.

Linux normally starts a process with three standard file descriptors:

```text
0 → Standard Input (stdin)
1 → Standard Output (stdout)
2 → Standard Error (stderr)
```

When `creat()` created `newfile.txt`, it returned:

```text
3
```

This happened because `0`, `1`, and `2` were already in use, and `3` was the lowest available file descriptor.

---

# Why Use `close()`?

After creating a file:

```c
close(fd);
```

closes the file descriptor.

Important:

```text
close(fd) does NOT delete the file.
```

It only releases the file descriptor used by the process.

The file:

```text
newfile.txt
```

continues to exist on disk.

If a program terminates, Linux automatically closes its open file descriptors. However, in a long-running program, repeatedly opening files without closing them can cause a file descriptor leak and eventually lead to the process reaching its open file limit.

---

# Experiment: File Descriptor Allocation and Reuse

## Program: `fd_experiment.c`

```c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd1, fd2, fd3;

    fd1 = creat("file1.txt", 0644);
    printf("file1.txt → FD = %d\n", fd1);

    fd2 = creat("file2.txt", 0644);
    printf("file2.txt → FD = %d\n", fd2);

    fd3 = creat("file3.txt", 0644);
    printf("file3.txt → FD = %d\n", fd3);

    close(fd2);

    printf("\nClosed FD %d (file2.txt)\n", fd2);

    int fd4 = creat("file4.txt", 0644);
    printf("file4.txt → FD = %d\n", fd4);

    close(fd1);
    close(fd3);
    close(fd4);

    return 0;
}
```

---

## Compilation

```bash
gcc fd_experiment.c -o fd_experiment
```

## Execution

```bash
./fd_experiment
```

### Expected Observation

Initially:

```text
0 → stdin
1 → stdout
2 → stderr
```

Therefore:

```text
file1.txt → FD 3
file2.txt → FD 4
file3.txt → FD 5
```

After:

```c
close(fd2);
```

File descriptor `4` becomes available again.

When `file4.txt` is created:

```text
file4.txt → FD 4
```

---

# Important Observation

Linux generally assigns the lowest available file descriptor when opening or creating a file.

Example:

```text
Open file1 → FD 3
Open file2 → FD 4
Open file3 → FD 5

Close FD 4

Create another file → FD 4 is reused
```

---

# Commands Used

```bash
gcc creat_file.c -o creat_file
./creat_file

ls -l newfile.txt

gcc fd_experiment.c -o fd_experiment
./fd_experiment

ls -la
```

---

# Important Concepts Learned

* `creat()` is used to create a file.
* `creat()` returns a file descriptor on success.
* `creat()` returns `-1` if an error occurs.
* File descriptors `0`, `1`, and `2` are normally used for standard input, standard output, and standard error.
* The first newly opened file commonly receives file descriptor `3`.
* Linux generally assigns the lowest available file descriptor.
* `close(fd)` releases a file descriptor.
* Closing a file descriptor does not delete the actual file.
* Closed file descriptor numbers can be reused.
* Not closing files in long-running programs can lead to file descriptor leaks.

---

## Conclusion

Through this experiment, I learned how Linux creates files using the `creat()` system call and how file descriptors are assigned and managed. I also observed that Linux generally reuses the lowest available file descriptor after a previously opened descriptor is closed.
