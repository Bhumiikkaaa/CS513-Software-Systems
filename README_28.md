# Question 28

## Question

Write a program to get maximum and minimum real-time priority.

---

## Objective

To obtain the minimum and maximum real-time priority values supported by the Linux system for the `SCHED_FIFO` scheduling policy.

---

## Program

### 28.c

The program uses:

```c
sched_get_priority_max(SCHED_FIFO);
sched_get_priority_min(SCHED_FIFO);
```

These functions return the maximum and minimum priority values supported for the specified scheduling policy.

### Important Concepts

#### `sched_get_priority_max()`

```c
sched_get_priority_max(SCHED_FIFO);
```

Returns the maximum real-time priority value supported by the `SCHED_FIFO` scheduling policy.

#### `sched_get_priority_min()`

```c
sched_get_priority_min(SCHED_FIFO);
```

Returns the minimum real-time priority value supported by the `SCHED_FIFO` scheduling policy.

On the system used for this experiment, the values were:

```text
Maximum priority = 99
Minimum priority = 1
```

---

## Commands Used

Compile:

```bash
gcc 28.c -o 28
```

Run:

```bash
./28
```

---

## Sample Output

```text
Maximum real-time priority : 99
Minimum real-time priority : 1
```

---

## Verification

The program successfully retrieved the real-time priority range supported by the system:

```text
Minimum = 1
Maximum = 99
```

---

## Key Learning

* Real-time scheduling policies use priority values.
* `sched_get_priority_min()` returns the minimum supported priority.
* `sched_get_priority_max()` returns the maximum supported priority.
* The priority range can depend on the scheduling policy and system.
* For `SCHED_FIFO` on this system, the supported range is **1–99**.
