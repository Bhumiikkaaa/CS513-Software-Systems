# Day 4: Opening Files Using `open()` System Call

## Objective

To understand the `open()` system call and experiment with:

* Opening an existing file in read-write mode using `O_RDWR`.
* Using `O_CREAT` to create a file if it does not exist.
* Using `O_EXCL` along with `O_CREAT` to prevent opening a file that already exists.
* Observing the file descriptor returned by `open()`.

---

# 1. Opening an Existing File Using `O_RDWR`

## Program

The program `open_file.c` opens an existing file named `existing_file.txt` using:

```c
open("existing_file.txt", O_RDWR);
```

`O_RDWR` allows the file to be opened for both reading and writing.

### Create the Existing File

Before running the program, the file must already exist.

```bash
touch existing_file.txt
```

### Compilation

```bash
gcc open_file.c -o open_file
```

### Execution

```bash
./open_file
```

### Output

```text
File opened successfully
File descriptor value: 3
```

### Check the File

```bash
ls -l existing_file.txt
```

The file remains empty because the program only opens and closes the file. No `read()` or `write()` operation is performed.

---

## Understanding the File Descriptor

The program returned:

```text
File descriptor value: 3
```

The first three file descriptors are normally:

```text
0 -> Standard Input
1 -> Standard Output
2 -> Standard Error
```

Therefore, when `open()` successfully opens a file, it usually returns the lowest available file descriptor.

In this case:

```text
3 -> existing_file.txt
```

---

# 2. Experimenting with `O_CREAT` and `O_EXCL`

## Program

The program `excl_experiment.c` uses:

```c
open("existing.txt", O_RDWR | O_CREAT | O_EXCL, 0644);
```

### Meaning of the Flags

```text
O_RDWR  -> Open the file for reading and writing.

O_CREAT -> Create the file if it does not exist.

O_EXCL  -> When used with O_CREAT, cause open() to fail if the
           file already exists.
```

The permission mode used is:

```text
0644
```

This corresponds to:

```text
Owner  -> Read and Write
Group  -> Read
Others -> Read
```

---

## First Experiment

Before running the program, we checked whether `existing.txt` existed:

```bash
ls -l existing.txt
```

Output:

```text
ls: cannot access 'existing.txt': No such file or directory
```

Since the file did not exist, we compiled and executed the program.

### Compilation

```bash
gcc excl_experiment.c -o excl_experiment
```

### Execution

```bash
./excl_experiment
```

### Output

```text
File opened successfully using O_EXCL
File descriptor value: 3
```

The file was then checked using:

```bash
ls -l existing.txt
```

The output showed that `existing.txt` was successfully created.

### Observation

```text
existing.txt does not exist
        |
        v
O_CREAT creates the file
        |
        v
O_EXCL allows creation because the file does not already exist
        |
        v
open() succeeds
```

---

# 3. Second `O_EXCL` Experiment

The program was executed again without deleting `existing.txt`.

```bash
./excl_experiment
```

Since the file already existed, `open()` failed.

Output:

```text
excl: File exists
```

### Observation

```text
existing.txt already exists
        |
        v
O_CREAT | O_EXCL
        |
        v
open() fails
```

---

# Comparison of File Opening Flags

| Flags                         | File Does Not Exist | File Already Exists |
| ----------------------------- | ------------------- | ------------------- |
| `O_RDWR`                      | Fails               | Opens successfully  |
| `O_RDWR \| O_CREAT`           | Creates and opens   | Opens successfully  |
| `O_RDWR \| O_CREAT \| O_EXCL` | Creates and opens   | Fails               |

---

# Important Concepts Learned

* `open()` is used to open files and returns a file descriptor on success.
* `O_RDWR` opens a file with both read and write access.
* `O_CREAT` creates a file if it does not already exist.
* `O_EXCL` is commonly used with `O_CREAT`.
* `O_CREAT | O_EXCL` ensures that a new file is created only if the file does not already exist.
* If the file already exists while using `O_CREAT | O_EXCL`, `open()` fails.
* File descriptors `0`, `1`, and `2` are generally reserved for standard input, standard output, and standard error.
* The `open()` system call usually returns the lowest available file descriptor.

---

# Files

```text
day_4/
├── open_file.c
├── excl_experiment.c
├── existing_file.txt
└── README.md
```
