# Day 1 – File Links and FIFO

## Topics Covered

* Files and inodes
* Hard links
* Soft links (Symbolic links)
* FIFO (Named Pipes)
* Shell commands
* System calls and library functions

---

# 1. File and Inode

A file is a collection of data stored on a computer.

An inode is a data structure that stores information about a file, such as:

* File permissions
* File owner
* File size
* Location of the file data
* Number of hard links

The filename is not stored inside the inode. A filename is associated with the inode through a directory entry.

---

# 2. Hard Link

A hard link is another filename that points to the same inode as an existing file.

Example:

```text
original.txt ───────┐
                    ├──→ Same inode → Same data
hard_link.txt ──────┘
```

## Creating a Hard Link Using Shell Command

```bash
ln original.txt hard_link.txt
```

To check inode numbers:

```bash
ls -li
```

### Observation

Both files have:

* The same inode number
* Access to the same data

If one hard link is deleted, the data still exists as long as another hard link points to the inode.

## Creating a Hard Link Using C

Function used:

```c
link()
```

Example:

```c
link("hard_link.txt", "hard_link_from_c.txt");
```

Both files created using this method point to the same inode.

---

# 3. Soft Link (Symbolic Link)

A soft link is a separate file that stores the path or name of another file.

Example:

```text
soft_link.txt
      ↓
hard_link.txt
      ↓
inode → Data
```

## Creating a Soft Link Using Shell Command

```bash
ln -s hard_link.txt soft_link.txt
```

To check details:

```bash
ls -li
```

### Observation

A soft link:

* Has a different inode from the target file
* Does not increase the hard-link count of the target
* Points to the filename or path of the target

If the target file is deleted, the soft link becomes a broken or dangling link.

## Creating a Soft Link Using C

Function used:

```c
symlink()
```

Example:

```c
symlink("hard_link.txt", "soft_link_from_c.txt");
```

---

# 4. FIFO (Named Pipe)

FIFO stands for:

**First In, First Out**

FIFO is a special type of file used for communication between processes.

Example:

```text
Process A → FIFO → Process B
```

The data written first into the FIFO is read first.

## Creating a FIFO Using Shell Command

```bash
mkfifo myfifo
```

To check the FIFO:

```bash
ls -l
```

A FIFO starts with:

```text
p
```

Example:

```text
prw-rw-r--
```

The first character `p` indicates that the file is a FIFO or named pipe.

## FIFO Communication Experiment

Terminal 1:

```bash
cat myfifo
```

Terminal 2:

```bash
echo "Hello from Process B" > myfifo
```

The message written in Terminal 2 appeared in Terminal 1.

## Creating a FIFO Using C

Function used:

```c
mkfifo()
```

Example:

```c
mkfifo("myfifo_from_c", 0666);
```

* `myfifo_from_c` → Name of the FIFO being created
* `0666` → Permissions for the FIFO

---

# 5. Shell Commands vs C Functions

| Shell Command       | C Function  |
| ------------------- | ----------- |
| `ln file1 file2`    | `link()`    |
| `ln -s file1 file2` | `symlink()` |
| `mkfifo myfifo`     | `mkfifo()`  |

Shell commands are written directly in the terminal and executed by the shell.

System call interfaces and library functions are called from inside a C program.

---

# 6. Compilation and Execution

Compile a C program:

```bash
gcc filename.c -o program_name
```

Example:

```bash
gcc soft_link.c -o soft_link
```

Here:

* `soft_link.c` → Input/source code
* `-o` → Specifies the output filename
* `soft_link` → Output executable

If `-o` is not used:

```bash
gcc soft_link.c
```

GCC usually creates an executable named:

```text
a.out
```

Run an executable:

```bash
./program_name
```

Example:

```bash
./soft_link
```

The `./` means to run the program from the current directory.

---

# 7. Commands Used Today

```bash
pwd
ls
ls -l
ls -li
touch filename
echo "text" > filename
echo "text" >> filename
cat filename
rm filename
ln original.txt hard_link.txt
ln -s target.txt soft_link.txt
mkfifo myfifo
nano filename
gcc filename.c -o program_name
./program_name
```

---

# Key Learnings

1. Hard links point to the same inode.
2. Soft links have their own inode and point to a filename or path.
3. Deleting one hard link does not delete the data if another hard link exists.
4. Deleting the target of a soft link breaks the soft link.
5. FIFO is used for communication between processes.
6. A FIFO can be identified by `p` at the beginning of its file type information in `ls -l`.
7. Shell commands are executed in the terminal, while functions such as `link()`, `symlink()`, and `mkfifo()` can be used inside C programs.

# 8. Exact Commands Used During Day 1

## Entering the Day 1 Directory

```bash
cd day_1
pwd
```

## Creating and Writing the Original File

```bash
touch original.txt
ls
echo "Hello Software Systems" > original.txt
cat original.txt
```

## Creating and Testing a Hard Link

```bash
ln original.txt hard_link.txt
ls -l
ls -li
```

Adding data through the hard link:

```bash
echo "This was added using hard_link.txt" >> hard_link.txt
cat original.txt
```

Deleting the original filename and testing the hard link:

```bash
rm original.txt
ls -li
cat hard_link.txt
```

## Cleaning Up an Accidental File

```bash
rm original_txt
ls -li
```

## Creating and Testing a Soft Link

Creating the soft link:

```bash
ln -s hard_link.txt soft_link.txt
ls -li
cat soft_link.txt
```

Deleting the target file:

```bash
rm hard_link.txt
ls -li
cat soft_link.txt
```

## Creating and Testing a FIFO

Creating the FIFO:

```bash
mkfifo myfifo
ls -l
```

Reading from the FIFO in Terminal 1:

```bash
cat myfifo
```

Writing to the FIFO from Terminal 2:

```bash
echo "Hello from Process B" > myfifo
```

## Creating a Soft Link Using a C Program

Creating and editing the program:

```bash
nano soft_link.c
```

Creating the target file:

```bash
echo "Hello from the C program experiment" > hard_link.txt
cat hard_link.txt
```

Compiling:

```bash
gcc soft_link.c -o soft_link
```

Running:

```bash
./soft_link
```

Verifying:

```bash
ls -li
cat soft_link_from_c.txt
```

## Creating a Hard Link Using a C Program

Creating the program:

```bash
nano hard_link.c
```

Compiling:

```bash
gcc hard_link.c -o hard_link_program
```

Running:

```bash
./hard_link_program
```

Verifying the inode numbers:

```bash
ls -li hard_link.txt hard_link_from_c.txt
```

## Creating a FIFO Using a C Program

Creating the program:

```bash
nano fifo.c
```

Compiling:

```bash
gcc fifo.c -o fifo_program
```

Running:

```bash
./fifo_program
```

Verifying the FIFO:

```bash
ls -l myfifo_from_c
```
