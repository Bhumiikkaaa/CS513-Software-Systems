# Day 9 – File Information using `stat()`

## Objective

Write a C program to print the following information about a given file:

- Inode number
- Number of hard links
- UID
- GID
- File size
- Block size
- Number of blocks
- Time of last access
- Time of last modification
- Time of last change

---

## Concept

Linux stores metadata about every file in an **inode**.

The `stat()` system call is used to obtain information about a file. It fills a `struct stat` structure with the file's metadata.

Basic syntax:

```c
struct stat st;

stat(filename, &st);
````

The required information is then available through fields of the `struct stat`.

### Important `struct stat` fields

| Field        | Information                |
| ------------ | -------------------------- |
| `st_ino`     | Inode number               |
| `st_nlink`   | Number of hard links       |
| `st_uid`     | User ID of owner           |
| `st_gid`     | Group ID of owner          |
| `st_size`    | File size in bytes         |
| `st_blksize` | Preferred block size       |
| `st_blocks`  | Number of allocated blocks |
| `st_atime`   | Last access time           |
| `st_mtime`   | Last modification time     |
| `st_ctime`   | Last status change time    |

---

## Timestamps

There are three important file timestamps:

### `st_atime`

Records the last time the file was accessed, such as when it is read.

### `st_mtime`

Records the last time the **contents of the file were modified**.

### `st_ctime`

Records the last time the file's **metadata or inode information changed**.

For example, changing file permissions using `chmod` changes `st_ctime`.

`st_ctime` does **not** mean file creation time.

---

## Program Working

The program first checks whether a filename has been provided through the command line.

For example:

```bash
./file_info file1
```

Here:

```text
./file_info → executable program
file1       → file given to the program
```

The filename is available through `argv[1]`.

The program then calls:

```c
stat(argv[1], &st);
```

If `stat()` succeeds, the requested information is extracted from the `struct stat` structure and displayed.

The `ctime()` function is used to convert the timestamp values into a readable date and time.

---

## Compilation

```bash
gcc file_info.c -o file_info
```

---

## Execution

```bash
./file_info file1
```

The program can also be used with another file:

```bash
./file_info file2
```

---

## Example Output

```text
Inode number      : 811607
Hard links        : 1
UID               : 1000
GID               : 1000
Size              : 12 bytes
Block size        : 4096 bytes
Blocks            : 8
Last access       : Wed Sep 16 01:29:31 2026
Last modification : Wed Sep 16 01:29:31 2026
Last change       : Wed Sep 16 01:29:31 2026
```

The exact inode number, UID, GID, size, block count, and timestamps depend on the file and system.

---

## Verification

Check the file using the Linux `stat` command:

```bash
stat file1
```

The information displayed by the command can be compared with the output of the C program.

---

## Key Learning

* `stat()` is used to obtain file metadata.
* `struct stat` stores information returned by `stat()`.
* `st_ino` gives the inode number.
* `st_nlink` gives the number of hard links.
* `st_uid` and `st_gid` identify the owner and group.
* `st_size` gives the file size in bytes.
* `st_blksize` gives the preferred I/O block size.
* `st_blocks` gives the number of allocated blocks.
* `st_atime`, `st_mtime`, and `st_ctime` represent different file timestamps.
* `st_ctime` represents a metadata/status change, not creation time.
* Command-line arguments allow the same executable to inspect different files.

````

Then save with **Ctrl+O → Enter → Ctrl+X**.

After that, run:

```bash
git status
git diff --check
````
