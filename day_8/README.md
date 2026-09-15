# Day 8 – Read a File Line by Line

## Objective

Write a C program to open a file in read-only mode, read it line by line, display each line as it is read, and close the file when the end of the file is reached.

---

## Concept

The program uses the `open()`, `read()`, `write()`, and `close()` system calls.

Although the assignment says "read line by line", the `read()` system call works with bytes, not lines.

Therefore, this program reads the file one character (one byte) at a time.

A newline character (`\n`) marks the end of a line. Since the program writes every character immediately, including `\n`, the original line structure is preserved on the output.

---

## System Calls Used

### 1. open()

```c
open("file1", O_RDONLY);
