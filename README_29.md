# Question 29

## Question

Write a program to get scheduling policy and modify the scheduling policy:

* `SCHED_FIFO`
* `SCHED_RR`

---

## Objective

To get the current scheduling policy of a process and modify it using `SCHED_FIFO` and `SCHED_RR`.

The program operates on the current process by passing `0` to the scheduling functions.

---

## Program

### 29.c

The program uses:

```c
sched_getscheduler(0);
sched_setscheduler(0, policy, &param);
```

### Important Concepts

#### `sched_getscheduler()`

```c id="f4e0x2"
policy = sched_getscheduler(0);
```

Returns the scheduling policy of the specified process.

Passing `0` refers to the calling process itself.

The program identifies the returned policy as:

* `SCHED_OTHER`
* `SCHED_FIFO`
* `SCHED_RR`

#### `sched_setscheduler()`

```c id="x9j2ps"
sched_setscheduler(0, SCHED_FIFO, &param);
```

Changes the scheduling policy of the current process to `SCHED_FIFO`.

The program then changes it to:

```c id="p0h1ss"
sched_setscheduler(0, SCHED_RR, &param);
```

### `struct sched_param`

The priority is supplied through:

```c id="k9q5sw"
struct sched_param param;
```

The program obtains the minimum valid priority for the selected real-time policy using:

```c id="z0q8rx"
sched_get_priority_min(SCHED_FIFO);
```

and:

```c id="x0r5yb"
sched_get_priority_min(SCHED_RR);
```

---

## Permissions

Changing a process to a real-time scheduling policy requires appropriate privileges.

On the system used for this experiment, running the program normally did not have sufficient permission, so it was executed using:

```bash id="c7d2ne"
sudo ./29
```

---

## Commands Used

Compile:

```bash id="j1m8v4"
gcc 29.c -o 29
```

Run with elevated privileges:

```bash id="g5x4sc"
sudo ./29
```

---

## Sample Output

```text id="p9v7k1"
Initial Scheduling Policy : SCHED_OTHER
After modification Scheduling Policy : SCHED_FIFO
After modification Scheduling Policy : SCHED_RR
```

---

## Verification

The output confirms that:

1. The initial scheduling policy was `SCHED_OTHER`.
2. The process was successfully changed to `SCHED_FIFO`.
3. The process was then successfully changed to `SCHED_RR`.

---

## Key Learning

* `sched_getscheduler()` retrieves the scheduling policy of a process.
* `sched_setscheduler()` changes the scheduling policy.
* `SCHED_FIFO` and `SCHED_RR` are real-time scheduling policies.
* `SCHED_FIFO` uses first-in, first-out scheduling among processes of the same priority.
* `SCHED_RR` uses round-robin scheduling among processes of the same priority.
* Appropriate privileges may be required to assign real-time scheduling policies.
