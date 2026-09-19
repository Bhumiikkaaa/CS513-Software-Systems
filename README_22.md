# Question 22 – Parent and Child Writing to the Same File

## Objective

Write a C program to open a file, call `fork()`, and then write to the file from both the child and parent processes. Check the contents of the file.

## Program

### 22.c

The program:

1. Opens `file.txt` for writing.
2. Calls `fork()` to create a child process.
3. The parent process writes `Parent Process` to the file.
4. The child process writes `Child Process` to the file.
5. The file is checked using `cat`.

## Important Concepts

### 1. Opening the File Before fork()

The file is opened before calling `fork()`:

fd = open("file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

The file descriptor is therefore available when the child process is created.

### 2. File Descriptor Inheritance

After `fork()`, the child inherits a copy of the parent's file descriptor.

Therefore, both processes can use `fd` to write to the same open file.

              open()
                |
              fd = 3
                |
              fork()
             /     \
        Parent     Child
          |          |
       write()     write()
          \          /
           file.txt

### 3. write()

The `write()` system call has the following form:

write(file_descriptor, buffer, number_of_bytes);

For example:

write(fd, "Child Process\n", 14);

Here:

* `fd` is the file descriptor.
* `"Child Process\n"` is the data.
* `14` is the number of bytes to write.

Similarly:

write(fd, "Parent Process\n", 15);

writes 15 bytes.

### 4. Execution Order

After `fork()`, the parent and child execute independently.

Therefore, the order in which they write to the file is not guaranteed.

Possible output:

Parent Process
Child Process

or:

Child Process
Parent Process

## Commands Used

### Compile

gcc 22.c -o 22

### Run

./22

### Check File Contents

cat file.txt

## Sample Output

One possible output is:

Parent Process
Child Process

The parent process happened to execute its `write()` before the child process.

The order may change on another execution because process scheduling is not deterministic.

## Verification

The file contains output written by both processes:

Parent Process
Child Process

This verifies that the child inherited the file descriptor after `fork()` and that both processes were able to write to the same file.

## Key Learning

* A child process inherits the parent's file descriptors after `fork()`.
* A file opened before `fork()` can be accessed by both parent and child.
* Both processes can write to the same open file.
* `write()` requires the number of bytes to be written.
* The execution order of parent and child is not guaranteed.

Create it with:

nano README_22.md
