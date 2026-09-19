# Question 26 – Execute an Executable Program

## Objective

Write programs to:

* Execute an executable program.
* Execute an executable program and pass an argument to it.

The `exec` family of system calls replaces the currently running process with another executable program.

---

## Program

### 26_a.c

This program uses `execlp()` to execute the existing `ls` executable with the arguments `-l /tmp`.

```c
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    printf("Executing ls -l /tmp\n");

    execlp("ls", "ls", "-l", "/tmp", (char *)NULL);

    perror("execlp");
    return EXIT_FAILURE;
}
```

### 26_b.c

This program uses `execlp()` to execute the existing `echo` executable and passes `Bhumika` as an argument.

```c
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    printf("Executing echo with an argument\n");

    execlp("echo", "echo", "Bhumika", (char *)NULL);

    perror("execlp");
    return EXIT_FAILURE;
}
```

---

## Important Concepts

### `exec()`

The `exec` family of system calls loads another executable program into the current process.

It **does not create a new process**. Instead, the currently running program is replaced.

### `execlp()`

Syntax:

```c
execlp(file, arg0, arg1, ..., NULL);
```

For example:

```c
execlp("ls", "ls", "-l", "/tmp", (char *)NULL);
```

Here:

* `"ls"` → executable to run
* second `"ls"` → `argv[0]`
* `"-l"` → argument to `ls`
* `"/tmp"` → argument to `ls`
* `NULL` → marks the end of the argument list

For 26(b):

```c
execlp("echo", "echo", "Bhumika", (char *)NULL);
```

`"Bhumika"` is passed as an argument to the `echo` executable.

### Why does `perror()` come after `execlp()`?

If `execlp()` succeeds, it does not return to the original program.

Therefore:

```c
perror("execlp");
```

is reached only when `execlp()` fails.

---

## Commands Used

### 26(a)

```bash
gcc 26_a.c -o 26_a
./26_a
```

### 26(b)

```bash
gcc 26_b.c -o 26_b
./26_b
```

---

## Sample Output

### 26(a)

```text
Executing ls -l /tmp
total 60
drwxr-xr-x 2 bhumika bhumika 4096 Sep 19 14:27 hsperfdata_bhumika
drwx------ 3 bhumika bhumika 4096 Sep 19 14:27 lu79562ytt4.tmp
srwxrwxr-x 1 bhumika bhumika    0 Sep 19 14:27 OSL_PIPE_1000_SingleOfficeIPC_7b61b374b653e9abbc43e587a664af
drwx------ 4 root root 4096 Sep 19 14:06 snap-private-tmp
...
```

### 26(b)

```text
Executing echo with an argument
Bhumika
```

---

## Verification

In 26(a), `execlp()` successfully executes `ls` and displays the contents of `/tmp`.

In 26(b), `execlp()` successfully executes `echo` and passes `Bhumika` as an argument.

The original program does not continue after a successful `exec`.

---

## Key Learning

* `exec` replaces the current process with another executable.
* `execlp()` can locate an executable using the `PATH` environment variable.
* Arguments can be passed to the executed program.
* `exec` does not create a new process.
* If `exec` succeeds, it does not return to the calling program.
