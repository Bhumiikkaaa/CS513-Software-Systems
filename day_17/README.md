# Day 17 – Online Ticket Reservation using File Locking

## Objective

Simulate online ticket reservation using a write lock.

The program:

1. Initializes a ticket number in a file.
2. Opens the file and obtains a write lock.
3. Reads the current ticket number.
4. Increments the number.
5. Writes the new ticket number back.
6. Releases the lock.

## Programs

### `ticket_init.c`

Initializes the ticket number in `ticket.txt`.

### `ticket_reserve.c`

Reserves the next ticket using a write lock.

## Important Concepts

### Ticket File

The ticket number is stored directly in:

```text
ticket.txt
```

The initialization program stores:

```c
int ticket = 0;
```

### Write Lock

The reservation program uses:

```c
lock.l_type = F_WRLCK;
```

A write lock ensures that two reservation processes do not modify the ticket number simultaneously.

### Read → Increment → Write

The critical section is:

```text
Read current ticket
       ↓
Increment ticket
       ↓
Write new ticket
```

The write lock protects this operation.

### `lseek()`

After reading the ticket number, the file offset is moved back to the beginning:

```c
lseek(fd, 0, SEEK_SET);
```

This allows the updated ticket number to be written at the beginning of the file.

## Commands Used

Initialize the ticket:

```bash
gcc ticket_init.c -o ticket_init
./ticket_init
```

Compile the reservation program:

```bash
gcc ticket_reserve.c -o ticket_reserve
./ticket_reserve
```

To observe locking, run `ticket_reserve` from two terminals.

## Sample Output

```text
Waiting to acquire write lock...
Write lock acquired.
New ticket number: 1
Write lock released.
```

Running it again produces the next ticket number:

```text
New ticket number: 2
```

## Verification

The stored ticket number can be inspected using:

```bash
od -An -td4 ticket.txt
```

## Key Learning

File locking prevents multiple processes from modifying shared data at the same time. The write lock protects the ticket-number update from race conditions.
