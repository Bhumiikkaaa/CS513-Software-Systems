````markdown
# Day 6 – read() and write() System Calls

## Objective

Write a program to take input from standard input (STDIN) and display it on standard output (STDOUT) using only the `read()` and `write()` system calls.

---

## Program

The program is implemented in `read_write.c`.

It reads input from the keyboard using the `read()` system call and displays the same input on the terminal using the `write()` system call.

### File

`read_write.c`

---

## System Calls Used

### 1. read()

```c
read(0, buffer, sizeof(buffer));
````

The `read()` system call reads data from a file descriptor and stores it in a buffer.

Here:

* `0` → STDIN
* `buffer` → stores the input
* `sizeof(buffer)` → maximum number of bytes to read

The `read()` system call returns the number of bytes actually read.

This value is stored in `n`.

---

### 2. write()

```c
write(1, buffer, n);
```

The `write()` system call writes data to a file descriptor.

Here:

* `1` → STDOUT
* `buffer` → contains the input data
* `n` → number of bytes actually read

Using `n` ensures that only the valid input data is displayed.

---

## File Descriptors

Linux provides three standard file descriptors:

| File Descriptor | Meaning |
| --------------- | ------- |
| 0               | STDIN   |
| 1               | STDOUT  |
| 2               | STDERR  |

In this program:

```text
Keyboard
   |
   v
STDIN (0)
   |
   v
read()
   |
   v
buffer
   |
   v
write()
   |
   v
STDOUT (1)
   |
   v
Terminal
```

---

## Compilation

Compile the program using:

```bash
gcc read_write.c -o read_write
```

---

## Execution

Run the program using:

```bash
./read_write
```

Enter some text and press Enter.

Example:

```text
Hello World
Hello World
```

The first line is the input entered through STDIN and the second line is the output produced through STDOUT.

---

## Important Concept

The program does not use functions such as:

```c
printf()
scanf()
fgets()
puts()
```

Instead, it directly uses the Linux system calls:

```c
read()
write()
```

This demonstrates how standard input and standard output can be handled at the system-call level.

---

## Key Learning

* STDIN has file descriptor `0`.
* STDOUT has file descriptor `1`.
* `read()` reads data from a file descriptor.
* `write()` writes data to a file descriptor.
* `read()` returns the number of bytes actually read.
* The returned byte count should be passed to `write()`.
* A buffer is used to temporarily store the input data.

````

Then save it.

After that, from the repository root:

```bash
cd ~/CS513-Software-Systems
git add .gitignore day_6/read_write.c day_6/README.md
git diff --cached --check
git status
````

We should see the **three intended changes** before committing.
