# Question 27

## Question

Write a program to execute `ls -Rl` by the following system calls:

a. `execl`
b. `execlp`
c. `execle`
d. `execv`
e. `execvp`

---

## Objective

To understand the different forms of the `exec` family of system calls by executing the `ls -Rl` command using each one.

The program creates a child process for each `exec` variant. The child process is replaced by `ls`, while the parent waits for the child to finish before executing the next variant.

---

## Program

### 27.c

The program demonstrates:

* `execl()`
* `execlp()`
* `execle()`
* `execv()`
* `execvp()`

### Important Concepts

#### 1. `execl()`

```c
execl("/bin/ls", "ls", "-Rl", NULL);
```

* Uses the complete path of the executable.
* Arguments are passed individually.
* Does not search the `PATH`.

#### 2. `execlp()`

```c
execlp("ls", "ls", "-Rl", NULL);
```

* Uses the executable name instead of the full path.
* The `p` means it searches the directories in `PATH`.
* Arguments are passed individually.

#### 3. `execle()`

```c
execle("/bin/ls", "ls", "-Rl", NULL, envp);
```

* Uses the complete path.
* Allows a custom environment to be supplied.
* In this program, the environment contains:

```c
char *envp[] = {"PATH=/bin", NULL};
```

#### 4. `execv()`

```c
char *args[] = {"ls", "-Rl", NULL};
execv("/bin/ls", args);
```

* Uses the complete path.
* Arguments are passed through an array.

#### 5. `execvp()`

```c
char *args[] = {"ls", "-Rl", NULL};
execvp("ls", args);
```

* Searches for the executable using `PATH`.
* Arguments are passed through an array.

---

## Why `fork()` is Used

An `exec` call replaces the current process. Therefore, if all five `exec` calls were made directly from the same process, the first successful `exec` would replace the program and the remaining calls would never execute.

The program therefore uses:

```c
fork()
```

before each `exec` call.

The parent then uses:

```c
wait(NULL);
```

to wait for the child to finish before moving to the next `exec` variant.

The execution flow is:

```text
Parent
  |
  +-- fork() --> Child --> execl()  --> ls -Rl
  |
  +-- fork() --> Child --> execlp() --> ls -Rl
  |
  +-- fork() --> Child --> execle() --> ls -Rl
  |
  +-- fork() --> Child --> execv()  --> ls -Rl
  |
  +-- fork() --> Child --> execvp() --> ls -Rl
```

---

## Commands Used

Compile:

```bash
gcc 27.c -o 27
```

Run:

```bash
./27
```

---

## Sample Output

```text
Parent PID = 20834: Executing 'ls -Rl'

--- Using execl ---
.:
total 420
...

--- Using execlp ---
.:
total 420
...

--- Using execle ---
.:
total 420
...

--- Using execv ---
.:
total 420
...

--- Using execvp ---
.:
total 420
...
```

The exact files and directory contents depend on the current contents of the repository.

---

## Verification

The output shows that `ls -Rl` was successfully executed using all five `exec` variants:

```text
execl
execlp
execle
execv
execvp
```

Each command produced the recursive directory listing.

---

## Key Learning

* The `exec` family replaces the current process image with another executable.
* `execl()` and `execlp()` pass arguments individually.
* `execv()` and `execvp()` pass arguments using an array.
* `execle()` allows an explicit environment to be supplied.
* `execl()` and `execv()` use an explicit executable path.
* `execlp()` and `execvp()` search for the executable using `PATH`.
* `fork()` allows the original parent process to continue after a child is replaced by `exec`.
* `wait()` allows the parent to execute the five variants sequentially.
