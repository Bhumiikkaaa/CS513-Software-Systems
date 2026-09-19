# Day 18 – Record Locking using `fcntl()`

## Objective

Write a program to perform record locking:

1. Implement write locking.
2. Implement read locking.
3. Create three records in a file.
4. Lock a particular record before accessing it to avoid race conditions.

## Programs

### `record_init.c`

Creates three records in `record.txt`.

### `record_lock.c`

Locks and accesses a selected record.

## Record Structure

Each record contains an ID and a name:

```c
struct record
{
    int id;
    char name[20];
};
```

Three records are stored:

```text
Record 1 → ID 1, Alice
Record 2 → ID 2, Bob
Record 3 → ID 3, Charlie
```

## Important Concepts

### Record as a Byte Range

Each record occupies:

```c
sizeof(struct record)
```

bytes.

The starting position of a selected record is calculated as:

```c
lock.l_start = (record_no - 1) * sizeof(struct record);
```

Therefore:

```text
Record 1 → 0
Record 2 → sizeof(struct record)
Record 3 → 2 * sizeof(struct record)
```

### Locking One Record

The program locks only the selected record:

```c
lock.l_len = sizeof(struct record);
```

This means different records can be locked independently.

For example, one process can lock Record 1 while another process locks Record 2.

### Write Lock

```c
lock.l_type = F_WRLCK;
```

A write lock prevents conflicting access to the selected record.

### Read Lock

```c
lock.l_type = F_RDLCK;
```

A read lock allows multiple readers but conflicts with a write lock.

## Commands Used

Create the records:

```bash
gcc record_init.c -o record_init
./record_init
```

Compile the locking program:

```bash
gcc record_lock.c -o record_lock
./record_lock
```

Enter a record number between 1 and 3.

## Sample Output

```text
Enter record number (1-3): 2
Waiting to acquire lock for record 2...
Record 2 locked.
ID: 2
Name: Bob
Record is locked. Press Enter to release it.
Record 2 unlocked.
```

## Verification

Run the locking program from two terminals.

For example:

* Terminal 1 → lock Record 1
* Terminal 2 → lock Record 2

The two processes can access different record ranges independently.

If both processes attempt to lock the same record with conflicting locks, the second process waits.

## Key Learning

Record locking protects only the required portion of a file instead of locking the entire file. This allows different processes to work with different records concurrently while preventing conflicting access to the same record.
