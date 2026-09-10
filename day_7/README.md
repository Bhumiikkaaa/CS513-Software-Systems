
# Day 7 – Copy a File Using System Calls

## Objective

Write a C program to copy the contents of `file1` into `file2`, similar to the Linux command:

```bash
cp file1 file2
```

The program performs the copying using the `open()`, `read()`, `write()`, and `close()` system calls.

---

## Concept

File copying can be performed by:

1. Opening the source file in read-only mode.
2. Opening the destination file in write mode.
3. Reading a portion of data from the source file into a buffer.
4. Writing the data from the buffer into the destination file.
5. Repeating the read and write operations until the entire file is copied.
6. Closing both files.

The program uses a buffer of 100 bytes to transfer the data.

---

## Program

### Source File: `file1`

The source file contains sample text:

```text
New content in file1
```

### C Program: `copy_file.c`

The program opens `file1` using `O_RDONLY` and opens `file2` using:

```c
O_WRONLY | O_CREAT | O_TRUNC
```

The contents are then copied using `read()` and `write()`.

---

## System Calls Used

### 1. `open()`

Used to open the source and destination files.

For the source:

```c
open("file1", O_RDONLY);
```

`O_RDONLY` opens the file in read-only mode.

For the destination:

```c
open("file2", O_WRONLY | O_CREAT | O_TRUNC, 0644);
```

The flags have the following meanings:

* `O_WRONLY` – open the file for writing.
* `O_CREAT` – create the file if it does not already exist.
* `O_TRUNC` – if the file already exists, remove its previous contents.
* `0644` – permissions used when a new file is created.

`O_TRUNC` is important because the behavior should be similar to:

```bash
cp file1 file2
```

If `file2` already contains data, the old contents should be replaced.

---

### 2. `read()`

```c
n = read(fd1, buffer, sizeof(buffer));
```

`read()` reads data from `file1` into the buffer.

The return value `n` represents the **actual number of bytes read**.

For example, even though the buffer can hold 100 bytes, if only 25 bytes are available:

```text
n = 25
```

Therefore, only those 25 bytes should be written to the destination.

---

### 3. `write()`

```c
write(fd2, buffer, n);
```

The data read from `file1` is written to `file2`.

The value `n` returned by `read()` is passed to `write()` so that exactly the number of bytes actually read are copied.

---

### 4. `close()`

```c
close(fd1);
close(fd2);
```

After copying is complete, both file descriptors are closed.

---

## Compilation

Compile the program using:

```bash
gcc copy_file.c -o copy_file
```

---

## Execution

Run the program:

```bash
./copy_file
```

The program does not produce any output on the terminal when the copy is successful.

---

## Verification

The contents of both files can be checked using:

```bash
cat file1
cat file2
```

To check whether both files are identical:

```bash
cmp file1 file2
```

If `cmp` produces no output, the two files are identical.

---

## Experiment with `O_TRUNC`

First, modify the contents of `file1`:

```bash
echo "New content in file1" > file1
```

Then run:

```bash
./copy_file
```

Now check:

```bash
cat file2
```

The new contents of `file1` will appear in `file2`.

This demonstrates the effect of the `O_TRUNC` flag: the previous contents of `file2` are removed before the new contents are written.

---

## File Descriptors

The `open()` system call returns a file descriptor for each successfully opened file.

The program stores these descriptors in:

```c
int fd1, fd2;
```

Typically, file descriptors `0`, `1`, and `2` are already used for:

```text
0 → Standard Input (STDIN)
1 → Standard Output (STDOUT)
2 → Standard Error (STDERR)
```

Therefore, the first files opened by the program will normally receive descriptors starting from `3`.

---

## Key Learning

* A file can be copied manually using system calls.
* `open()` is used to obtain file descriptors for files.
* `read()` transfers data from a file into a buffer.
* `write()` transfers data from the buffer into another file.
* The return value of `read()` tells us how many bytes were actually read.
* `O_CREAT` creates the destination file if it does not exist.
* `O_TRUNC` removes the previous contents of an existing destination file.
* `close()` releases the file descriptors after the operation is complete.
* The program demonstrates the basic mechanism behind file-copying operations such as `cp`.

---

## Commands Used

```bash
gcc copy_file.c -o copy_file
./copy_file
cat file1
cat file2
cmp file1 file2

