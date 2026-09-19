# Question 30

## Question

Write a program to run a script at a specific time using a daemon process.

---

## Objective

To create a daemon process that waits until a specified time and then executes a shell script.

The program uses `fork()` to create the daemon process, `setsid()` to create a new session, and `system()` to execute the script.

---

## Program

### 30.c

The program accepts three command-line arguments:

```text
<hour> <minute> <script>
```

For example:

```bash
./30 21 56 test.sh
```

The daemon waits until the specified hour and minute and then executes the script.

### Important Concepts

#### 1. `fork()`

```c
pid = fork();
```

Creates a child process. The parent exits while the child continues running as the daemon.

#### 2. `setsid()`

```c
setsid();
```

Creates a new session for the child process and allows it to run independently of the terminal.

#### 3. `chdir()` and `umask()`

```c
chdir("/");
umask(0);
```

The daemon changes its working directory to `/` and resets the file creation mask.

The script path is converted to an absolute path using `realpath()` before changing the working directory.

#### 4. Waiting for the specified time

The program repeatedly obtains the current time using:

```c
time(NULL);
localtime(&now);
```

It compares the current hour and minute with the requested time:

```c
if (current_time->tm_hour == target_hour &&
    current_time->tm_min == target_minute)
```

The daemon sleeps for one second between checks.

#### 5. Executing the script

Once the specified time is reached:

```c
system(command);
```

executes the shell script.

---

## Test Script

The following script was used:

```bash
#!/bin/bash
echo "Script executed at $(date)" >> /tmp/script_output.txt
```

The script records the execution time in:

```text
/tmp/script_output.txt
```

---

## Commands Used

Compile:

```bash
gcc 30.c -o 30
```

Check the current time:

```bash
date
```

Run the daemon:

```bash
./30 <hour> <minute> test.sh
```

Example:

```bash
./30 21 56 test.sh
```

Check the script output:

```bash
cat /tmp/script_output.txt
```

---

## Sample Output

Daemon started:

```text
Daemon started with PID: 22096
```

After the specified time:

```text
Script executed at Sat Sep 19 09:56:45 PM IST 2026
```

---

## Verification

The program was tested by specifying the current time as the target time.

The daemon started successfully and executed `test.sh`. The script created `/tmp/script_output.txt` and recorded the execution time.

---

## Key Learning

* A daemon process can run independently in the background.
* `fork()` creates the child process that continues as the daemon.
* `setsid()` creates a new session.
* A daemon can continuously check the system time and perform an operation at a specified time.
* `system()` can be used to execute a shell script.
* `realpath()` is useful when a daemon changes its working directory because it preserves the correct location of the script.
