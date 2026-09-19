# Day 12 – Finding the Opening Mode of a File

## Objective

Write a program to find out the opening mode of a file using `fcntl()`.

The program checks whether the file was opened in:

* Read-only mode
* Write-only mode
* Read-write mode

## Program

### opening_mode.c

The program:

1. Opens `file4`.
2. Uses `fcntl()` with `F_GETFL` to retrieve the file status flags.
3. Extracts the access mode using `O_ACCMODE`.
4. Checks whether the file was opened with `O_RDONLY`, `O_WRONLY`, or `O_RDWR`.
5. Displays the corresponding opening mode.
6. Closes the file.

## Important Concepts

### fcntl()

`fcntl()` is used to perform various operations on an open file descriptor.

In this program:

```c
flags = fcntl(fd, F_GETFL);
```

`F_GETFL` retrieves the file status flags associated with the file descriptor.

### O_ACCMODE

The access mode is extracted using:

```c
flags & O_ACCMODE
```

The result can then be compared with:

```c
O_RDONLY
O_WRONLY
O_RDWR
```

Example:

```c
if ((flags & O_ACCMODE) == O_RDONLY)
    printf("File is opened in read-only mode\n");
else if ((flags & O_ACCMODE) == O_WRONLY)
    printf("File is opened in write-only mode\n");
else if ((flags & O_ACCMODE) == O_RDWR)
    printf("File is opened in read-write mode\n");
```

## Opening the File

The program opens the file using:

```c
open("file4", O_RDWR | O_CREAT, 0644);
```

Here:

* `O_RDWR` opens the file for both reading and writing.
* `O_CREAT` creates the file if it does not already exist.
* `0644` specifies the permissions when the file is created.

Therefore, the expected output is:

```text
File is opened in read-write mode
```

The `open()` mode can be changed to test the other cases.

For read-only mode:

```c
open("file4", O_RDONLY);
```

For write-only mode:

```c
open("file4", O_WRONLY);
```

## Commands Used

Create the source file:

```bash
nano opening_mode.c
```

Compilation:

```bash
gcc opening_mode.c -o opening_mode
```

Execution:

```bash
./opening_mode
```

Check the file:

```bash
ls -l file4
```

## Sample Output

```text
File is opened in read-write mode
```

## Verification

The program was tested by changing the `open()` access mode to:

```text
O_RDONLY
O_WRONLY
O_RDWR
```

and verifying that `fcntl(F_GETFL)` correctly identified each opening mode.

## Key Learning

* `fcntl()` can retrieve file status flags using `F_GETFL`.
* `O_ACCMODE` is used to extract the access mode.
* `O_RDONLY`, `O_WRONLY`, and `O_RDWR` represent the three basic access modes.
* The opening mode is associated with the file descriptor.
* `fcntl()` can inspect properties of an already-open file descriptor.
