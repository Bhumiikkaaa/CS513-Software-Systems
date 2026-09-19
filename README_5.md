# Day 5 – File Descriptor Table Using `/proc`

## Objective

Write a C program that creates five files, keeps all five files open using file descriptors, executes the program in the background, and examines the process's file descriptor table through:

```bash
/proc/<PID>/fd
```

---

## Program

The program creates five files using the `creat()` system call.

For each iteration:

1. A unique filename is generated.
2. `creat()` creates and opens the file.
3. The returned file descriptor is printed.
4. The file descriptor is not closed.

After creating all five files, the program enters an infinite loop so that the process continues running and the file descriptors remain open.

The program uses:

```c
sprintf(filename, "file%d", i + 1);
```

to generate filenames such as:

```text
file1
file2
file3
file4
file5
```

---

## Compilation

Compile the program using:

```bash
gcc five_file.c -o five_file
```

Run it:

```bash
./five_file
```

The program produces output similar to:

```text
file1 created with file descriptor 3
file2 created with file descriptor 4
file3 created with file descriptor 5
file4 created with file descriptor 6
file5 created with file descriptor 7
```

The program then continues running because of the infinite loop.

Press:

```text
Ctrl+C
```

to terminate a foreground execution.

---

## Running in the Background

The program can be executed in the background using:

```bash
./five_file &
```

The shell displays the process ID (PID), for example:

```text
[3] 11760
```

Here:

* `[3]` is the shell's job number.
* `11760` is the process ID (PID).

The PID is required to inspect the process through `/proc`.

---

## Checking the File Descriptor Table

For a process with PID `11760`, run:

```bash
ls -l /proc/11760/fd
```

Example output:

```text
0 -> /dev/pts/0
1 -> /dev/pts/0
2 -> /dev/pts/0
3 -> /home/bhumika/CS513-Software-Systems/day_5/file1
4 -> /home/bhumika/CS513-Software-Systems/day_5/file2
5 -> /home/bhumika/CS513-Software-Systems/day_5/file3
6 -> /home/bhumika/CS513-Software-Systems/day_5/file4
7 -> /home/bhumika/CS513-Software-Systems/day_5/file5
```

---

## Understanding the File Descriptors

Every process normally starts with three standard file descriptors:

| FD | Meaning                    |
| -- | -------------------------- |
| 0  | Standard input (`stdin`)   |
| 1  | Standard output (`stdout`) |
| 2  | Standard error (`stderr`)  |

Therefore, the first file created by the program receives FD `3`.

The next files receive FDs `4`, `5`, `6`, and `7`.

The resulting mapping is:

```text
FD 3 → file1
FD 4 → file2
FD 5 → file3
FD 6 → file4
FD 7 → file5
```

The files remain visible under `/proc/<PID>/fd` because the program does not call `close()` on these descriptors.

---

## Why `/proc/<PID>/fd` Is Useful

Linux exposes information about running processes through the `/proc` virtual filesystem.

The directory:

```bash
/proc/<PID>/fd
```

contains symbolic links representing the file descriptors currently open by that process.

For example:

```text
3 -> /home/bhumika/CS513-Software-Systems/day_5/file1
```

means that file descriptor `3` currently refers to `file1`.

Thus, `/proc/<PID>/fd` provides a direct way to inspect which files or resources a running process currently has open.

---

## Important Observation

The five created files do not contain copies of the C program.

The C source code is stored in:

```text
five_file.c
```

The files `file1` through `file5` are separate files created and opened by the running process.

The process simply maintains file descriptors pointing to those files.

---

## Process Cleanup

After completing the `/proc` experiment, the background process can be terminated using:

```bash
kill <PID>
```

For example:

```bash
kill 11760
```

The `kill` command sends a termination signal to the process.

After the process terminates, its `/proc/<PID>/fd` directory disappears because `/proc` only exposes information about currently existing processes.

---

## Key Concepts Learned

* `creat()` creates and opens a file.
* A successful `creat()` call returns a file descriptor.
* File descriptors `0`, `1`, and `2` are reserved for standard input, output, and error.
* Newly opened files normally receive the lowest available file descriptor.
* File descriptors remain open until explicitly closed or until the process terminates.
* Background execution can be performed using `&`.
* A process ID (PID) identifies a running process.
* `/proc/<PID>/fd` can be used to inspect a process's open file descriptors.
* Linux represents open file descriptors inside `/proc` using symbolic links.
* An infinite loop can be used to keep a process alive while inspecting its state.
