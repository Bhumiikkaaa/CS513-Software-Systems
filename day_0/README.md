# Day 0 - Software Systems Fundamentals

## Topics Learned

### 1. Operating System
An Operating System manages computer hardware resources and provides services to applications.

### 2. Kernel
The Kernel is the core component of an Operating System. It manages important resources such as CPU, memory, files, and devices.

### 3. User Space and Kernel Space
Normal applications run in User Space with limited privileges.

The Kernel runs in Kernel Space and has access to important system resources.

### 4. System Call
A system call is a way for a user program to request services from the Operating System kernel.

Example:

User Program -> System Call -> Kernel -> Resource

### 5. Terminal
The Terminal is an interface where we type commands.

### 6. Shell
The Shell interprets and executes commands given through the terminal.

### 7. Compilation
A C source file is compiled using GCC to create an executable program.

Example:

gcc program.c -o program

The executable can then be run using:

./program

### 8. Program vs Process

Program:
A program is code stored on the disk.

Process:
A process is a program that is currently executing.
