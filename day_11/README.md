# Day 11 – File Descriptor Duplication and fcntl()

## Objective

Study file descriptor duplication using `dup()`, `dup2()`, and `fcntl()`.

Also find out the opening mode of a file using `fcntl()`.

## Programs

### 1. dup_file.c

Uses `dup()` to duplicate a file descriptor and append data using both descriptors.

### 2. dup2_file.c

Uses `dup2()` to duplicate a file descriptor to a specified file descriptor number and append data using both descriptors.

### 3. fcntl_file.c

Uses `fcntl()` with `F_DUPFD` to duplicate a file descriptor and append data using both descriptors.

### 4. opening_mode.c

Uses `fcntl()` with `F_GETFL` to find out whether a file was opened in read-only, write-only, or read-write mode.

## Important Concepts

### dup()

```c
dup(fd);
```

`dup()` creates a new file descriptor referring to the same open file description.

The kernel chooses the lowest available file descriptor number.

For example:

```text
Original FD : 3
Duplicate FD: 4
```

### dup2()

```c
dup2(fd, target);
```

`dup2()` duplicates a file descriptor into a specified file descriptor number.

For example:

```c
dup2(fd1, 10);
```

creates the duplicate as FD 10.

If the target descriptor is already open, `dup2()` closes it before performing the duplication.

### fcntl()

`fcntl()` is a general-purpose file descriptor control system call.

For duplication, the program uses:

```c
fcntl(fd1, F_DUPFD, 0);
```

`F_DUPFD` tells `fcntl()` to duplicate the descriptor and select the lowest available descriptor number greater than or equal to the specified minimum.

## Open File Description

The duplicated file descriptors refer to the same **open file description**.

Therefore, they share information such as:

* File offset
* File status flags

The descriptors themselves are different numbers.

For example:

```text
FD 3 ──┐
       ├──> Same open file description ──> file1
FD 4 ──┘
```

## O_APPEND

The duplication programs open the files using:

```c
O_RDWR | O_CREAT | O_APPEND
```

`O_APPEND` causes each `write()` to place the data at the end of the file.

Therefore, data written through either duplicated descriptor is appended to the same file.

Running the program multiple times will append additional data each time.

## Finding the Opening Mode

The `opening_mode.c` program uses:

```c
flags = fcntl(fd, F_GETFL);
```

`F_GETFL` retrieves the file status flags associated with the open file description.

The access mode is extracted using:

```c
flags & O_ACCMODE
```

The result can be compared with:

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

## Commands Used

### dup()

Create the source file:

```bash
nano dup_file.c
```

Compile:

```bash
gcc dup_file.c -o dup_file
```

Run:

```bash
./dup_file
```

Check contents:

```bash
cat file1
```

### dup2()

Create the source file:

```bash
nano dup2_file.c
```

Compile:

```bash
gcc dup2_file.c -o dup2_file
```

Run:

```bash
./dup2_file
```

Check contents:

```bash
cat file2
```

### fcntl()

Create the source file:

```bash
nano fcntl_file.c
```

Compile:

```bash
gcc fcntl_file.c -o fcntl_file
```

Run:

```bash
./fcntl_file
```

Check contents:

```bash
cat file3
```

### Opening Mode

Create the source file:

```bash
nano opening_mode.c
```

Compile:

```bash
gcc opening_mode.c -o opening_mode
```

Run:

```bash
./opening_mode
```

## Checking File Contents

The files can also be inspected byte by byte:

```bash
od -c file1
od -c file2
od -c file3
```

## Sample Output

### dup()

```text
Original FD : 3
Duplicate FD: 4
```

### dup2()

```text
Original FD : 3
Duplicate FD: 10
```

### fcntl()

```text
Original FD : 3
Duplicate FD: 4
```

### Opening Mode

```text
File is opened in read-write mode
```

## Key Learning

* `dup()` creates a duplicate FD using the lowest available descriptor.
* `dup2()` allows a specific FD number to be chosen.
* `fcntl()` can duplicate descriptors using `F_DUPFD`.
* Duplicated descriptors refer to the same open file description.
* `O_APPEND` makes writes occur at the end of the file.
* `F_GETFL` retrieves file status flags.
* `O_ACCMODE` can be used to determine the access mode.
* `O_RDONLY`, `O_WRONLY`, and `O_RDWR` represent the three basic access modes.
