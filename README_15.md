# Day 15 – Environment Variables using `environ`

## Objective

Write a program to display the environment variables of the user using the `environ` variable.

## Program

### `environment.c`

The program accesses the process environment using `environ` and displays each environment variable.

Each environment variable is stored as a string in the form:

```text
NAME=VALUE
```

The program continues printing until it reaches the `NULL` pointer marking the end of the environment.

## Important Concepts

### Environment Variables

Environment variables are name-value pairs provided to a process by its environment.

Examples:

```text
USER=bhumika
HOME=/home/bhumika
SHELL=/bin/bash
PWD=/home/bhumika/CS513-Software-Systems/day_15
PATH=...
```

### `environ`

`environ` provides access to the environment variables of the current process.

It is declared as:

```c
extern char **environ;
```

The environment can be viewed conceptually as:

```text
environ
   |
   ├── "USER=bhumika"
   ├── "HOME=/home/bhumika"
   ├── "SHELL=/bin/bash"
   ├── "PATH=..."
   ├── ...
   └── NULL
```

### Traversing `environ`

The program uses a pointer to traverse the environment:

```c
char **env = environ;

while (*env != NULL)
{
    printf("%s\n", *env);
    env++;
}
```

`env++` moves to the next environment variable, and the loop stops when `*env` becomes `NULL`.

## Commands Used

```bash
gcc environment.c -o environment
./environment
```

## Sample Output

```text
SHELL=/bin/bash
USER=bhumika
HOME=/home/bhumika
PWD=/home/bhumika/CS513-Software-Systems/day_15
PATH=...
LOGNAME=bhumika
...
```

The exact environment variables and their values depend on the user's system and current shell/session.

## Verification

The program was compiled and executed successfully. It displayed the environment variables available to the process.

## Key Learning

`environ` provides access to the process's environment as an array of strings. Each entry contains an environment variable in `NAME=VALUE` format, and the array ends with `NULL`.
