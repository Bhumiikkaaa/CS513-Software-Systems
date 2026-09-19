# Day 10 – lseek() and File Holes

## Objective

Write a program to open a file in read-write mode, write 10 bytes, move the file pointer forward by 10 bytes using `lseek()`, and write another 10 bytes.

Also check the return value of `lseek()` and inspect the empty space created between the two sets of data using `od`.

## Program

### lseek_write.c

The program:

1. Opens `file1` in read-write mode.
2. Creates the file if it does not exist.
3. Truncates the file if it already exists.
4. Writes the first 10 bytes.
5. Uses `lseek()` to move the file pointer forward by 10 bytes.
6. Checks the return value of `lseek()`.
7. Writes another 10 bytes.
8. Closes the file.

## Important Concepts

### lseek()

`lseek()` changes the current file offset.

Syntax:

```c
lseek(fd, offset, whence);
```

In this program:

```c
position = lseek(fd, 10, SEEK_CUR);
```

means move the file pointer 10 bytes forward from its current position.

After writing the first 10 bytes, the file offset is 10.

Moving it forward by another 10 bytes makes the new position:

```text
20
```

Therefore, the return value of `lseek()` should be 20.

### Return Value of lseek()

`lseek()` returns the new file offset on success.

It returns `-1` if an error occurs.

### File Hole

After the first 10 bytes are written, the file offset is 10.

`lseek()` moves the offset to 20 without writing anything between positions 10 and 19.

When the second 10 bytes are written, a gap exists between the two sets of data.

This gap is called a **file hole**.

The skipped region reads as null bytes (`\0`), not ordinary spaces.

## Program Structure

The file is opened using:

```c
open("file1", O_RDWR | O_CREAT | O_TRUNC, 0644);
```

The first 10 bytes are:

```text
ABCDEFGHIJ
```

The file pointer is then moved:

```c
lseek(fd, 10, SEEK_CUR);
```

The second 10 bytes are:

```text
KLMNOPQRST
```

Therefore, the logical file layout is:

```text
ABCDEFGHIJ
          [10-byte hole]
                    KLMNOPQRST
```

## Commands Used

Create the source file:

```bash
nano lseek_write.c
```

Compilation:

```bash
gcc lseek_write.c -o lseek_write
```

Execution:

```bash
./lseek_write
```

Check the file contents:

```bash
cat file1
```

Check the file byte by byte:

```bash
od -c file1
```

Check the file size:

```bash
ls -l file1
```

## Sample Output

```text
New file position: 20
```

## Verification

Using:

```bash
od -c file1
```

shows the first 10 characters, the null-byte region created by the file hole, and the final 10 characters.

The logical file size is:

```text
10 + 10 + 10 = 30 bytes
```

The middle 10 bytes contain no data written by the program; they are the hole created by moving the file offset beyond the current end of the file.

## Key Learning

* `lseek()` changes the file offset.
* `lseek()` does not write data.
* The return value of `lseek()` is the new file position.
* Moving beyond EOF and then writing creates a file hole.
* A file hole contains null bytes when read.
* `od -c` can be used to inspect the contents byte by byte.
