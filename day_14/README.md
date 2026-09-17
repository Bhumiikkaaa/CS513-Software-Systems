# Day 14 – File Type Identification

## Objective

Write a program to identify the type of a file. The file path is provided through the command line.

## Program

### `file_type.c`

The program takes a file path as a command-line argument and uses `lstat()` to identify the type of the filesystem object.

It can identify regular files, directories, symbolic links, FIFOs, character devices, block devices, and sockets.

## Important Concepts

### Command-Line Arguments

The file path is supplied when running the program:

```bash
./file_type <file_path>
```

The program accesses the path using:

```c
argv[1]
```

### `lstat()`

`lstat()` obtains information about the specified filesystem object and stores it in a `struct stat`.

The `st_mode` field is used to determine the object's type.

### File Type Macros

The program uses macros provided by `<sys/stat.h>`:

```text
S_ISREG()   → regular file
S_ISDIR()   → directory
S_ISLNK()   → symbolic link
S_ISFIFO()  → FIFO
S_ISCHR()   → character device
S_ISBLK()   → block device
S_ISSOCK()  → socket
```

## Commands Used

```bash
gcc file_type.c -o file_type
./file_type <file_path>
```

Examples:

```bash
./file_type ../day_9/file1
./file_type .
```

## Sample Output

```text
../day_9/file1 is a regular file.
. is a directory.
```

## Verification

The program was tested using a regular file and the current directory.

It correctly identified the regular file as a regular file and the current directory as a directory.

## Key Learning

`lstat()` can be used to obtain filesystem metadata, and the `st_mode` field together with the `S_IS*()` macros can be used to determine the type of a filesystem object.
