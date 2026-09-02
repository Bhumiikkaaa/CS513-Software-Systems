# Day 0 - Software Systems Fundamentals and Environment Setup

## Objectives

On Day 0, I learned the basic concepts required to begin studying Software Systems and set up my working environment using Ubuntu, Git, and GitHub.

---

# 1. Concepts Learned

## Operating System

An Operating System (OS) manages computer hardware resources and provides services to applications.

## Kernel

The Kernel is the core component of an Operating System.

It manages important system resources such as:

* CPU
* Memory
* Files
* Hardware devices
* Processes

## System Call

A system call is a way for a user program to request services from the Operating System kernel.

Example:

```text
User Program
     ↓
System Call
     ↓
Kernel
     ↓
Hardware / System Resource
```

## Terminal

The Terminal is an interface where users can type commands and interact with the operating system.

## Shell

The Shell interprets and executes commands entered through the terminal.

## Compilation

A C program is written in a `.c` file.

The GCC compiler converts the C source code into an executable program.

```text
program.c
    ↓
   GCC
    ↓
Executable Program
    ↓
./program
```

## Program vs Process

### Program

A program is code stored on the disk.

### Process

A process is a program that is currently executing.

---

# 2. Linux Commands Learned

## `pwd`

### Description

`pwd` stands for **Print Working Directory**.

It displays the complete path of the directory where we are currently located.

### Syntax

```bash
pwd
```

### Example

```bash
pwd
```

### Related Commands

* `cd` — Change directory
* `ls` — List files and directories

---

## `cd`

### Description

`cd` stands for **Change Directory**.

It is used to move from one directory to another.

### Move into a directory

```bash
cd directory_name
```

Example:

```bash
cd day_0
```

### Move to the parent directory

```bash
cd ..
```

### Move to the home directory

```bash
cd ~
```

### Useful Alternative

```bash
cd
```

This also usually takes us to the home directory.

---

## `ls`

### Description

`ls` is used to list files and directories.

### Basic Usage

```bash
ls
```

### Alternatives and Options

#### Detailed listing

```bash
ls -l
```

Shows detailed information such as:

* Permissions
* Owner
* File size
* Modification time

#### Show hidden files

```bash
ls -a
```

#### Detailed listing including hidden files

```bash
ls -la
```

### When to Use

* `ls` → Quick view
* `ls -l` → Detailed information
* `ls -a` → Show hidden files
* `ls -la` → Detailed information including hidden files

---

## `mkdir`

### Description

`mkdir` stands for **Make Directory**.

It creates a new directory.

### Syntax

```bash
mkdir directory_name
```

### Example

```bash
mkdir HandsOn-List-1
```

### Create Multiple Directories

```bash
mkdir day_1 day_2 day_3
```

### Alternative: Create Nested Directories

```bash
mkdir -p parent/child
```

The `-p` option creates parent directories if they do not already exist.

---

## `cat`

### Description

`cat` displays the contents of a file in the terminal.

### Syntax

```bash
cat filename
```

### Example

```bash
cat day_0/README.md
```

### Alternatives

#### `less`

```bash
less filename
```

Useful for viewing large files page by page.

#### `more`

```bash
more filename
```

Another command for viewing files page by page.

### When to Use

* `cat` → Small files
* `less` → Large files and easier navigation
* `more` → Basic page-by-page viewing

---

# 3. Nano Text Editor

## `nano`

### Description

`nano` is a terminal-based text editor.

We used it to create and edit the `README.md` file.

### Open or Create a File

```bash
nano README.md
```

### Open a File Using Its Path

```bash
nano day_0/README.md
```

## Important Nano Shortcuts

### Save the File

```text
Ctrl + O
```

Then press:

```text
Enter
```

### Exit Nano

```text
Ctrl + X
```

---

# 4. GCC Compiler

## Check GCC Version

```bash
gcc --version
```

## Compile a C Program

### Syntax

```bash
gcc filename.c -o program_name
```

### Example

```bash
gcc program.c -o program
```

## Run the Program

```bash
./program
```

### Complete Example

```bash
gcc program.c -o program
./program
```

---

# 5. Git Commands Learned

## `git --version`

### Description

Displays the installed version of Git.

### Command

```bash
git --version
```

### Example Output

```text
git version 2.43.0
```

---

## `git config`

### Description

Used to configure Git settings.

## Set Git Username

```bash
git config --global user.name "Your Name"
```

## Set Git Email

```bash
git config --global user.email "your-email@example.com"
```

## Check Git Configuration

```bash
git config --global --list
```

### Important

The `--global` option applies the configuration to all Git repositories on the computer for that user.

---

## `git clone`

### Description

Creates a local copy of a remote GitHub repository.

### Syntax

```bash
git clone repository_URL
```

### Example

```bash
git clone https://github.com/username/CS513-Software-Systems.git
```

After cloning:

```bash
cd CS513-Software-Systems
```

---

## `git status`

### Description

Shows the current status of the Git repository.

It can show:

* Untracked files
* Modified files
* Staged files
* Whether the working directory is clean

### Command

```bash
git status
```

### Example: Untracked File

```text
Untracked files:
    day_0/
```

This means Git can see the file or folder, but it is not tracking it yet.

---

## `git add`

### Description

Adds files or changes to the **staging area**.

### Add a Specific File

```bash
git add filename
```

### Add a Folder

```bash
git add day_0
```

### Add All Changes

```bash
git add .
```

### Important Observation

When `git add` is successful, it usually produces **no output**.

### Important

`git add` does **not** upload files to GitHub.

It only prepares the changes for a commit.

---

## `git commit`

### Description

Creates a saved checkpoint in the local Git repository.

### Syntax

```bash
git commit -m "Commit message"
```

### Example Used

```bash
git commit -m "Add Day 0 Software System fundamentals notes"
```

### Meaning of `-m`

`-m` allows us to provide a commit message directly in the command.

---

## `git push`

### Description

Uploads committed changes from the local Git repository to the remote repository on GitHub.

### Command

```bash
git push
```

### Authentication

Since the repository uses HTTPS, GitHub may ask for:

```text
Username for 'https://github.com':
```

Enter the GitHub username.

GitHub may then ask for a password.

For HTTPS Git authentication, a **Personal Access Token (PAT)** can be used instead of the normal GitHub account password.

### Important Observation

When pasting a token into the terminal password prompt:

* Characters may not appear on the screen.
* No dots or stars may be displayed.
* This is normal for password input.

---

# 6. GitHub Setup

## Repository Created

Repository name:

```text
CS513-Software-Systems
```

## Repository Cloning Workflow

```text
GitHub Repository
       ↓
Copy HTTPS URL
       ↓
git clone
       ↓
Local Repository in Ubuntu
```

---

# 7. Git Workflow Learned

The standard workflow used to save progress is:

```text
Create or Modify Files
        ↓
git status
        ↓
git add
        ↓
Staging Area
        ↓
git commit
        ↓
Local Git Repository
        ↓
git push
        ↓
GitHub Repository
```

---

# 8. Important Git Concepts

## Working Directory

The files we are currently creating or modifying.

## Untracked Files

Files that Git can see but is not tracking yet.

Example:

```text
Untracked files:
    day_0/
```

## Staging Area

The area where changes are prepared before creating a commit.

We move changes to the staging area using:

```bash
git add
```

## Commit

A saved checkpoint in the local Git repository.

Created using:

```bash
git commit
```

## Remote Repository

The repository stored online on GitHub.

## Push

Uploading local commits to the remote GitHub repository.

```bash
git push
```

---

# 9. Commands Used Sequentially on Day 0

## Check Current Location

```bash
pwd
```

## Go to Home Directory

```bash
cd ~
```

## Check Files and Folders

```bash
ls
```

## Check GCC Installation

```bash
gcc --version
```

## Check Git Installation

```bash
git --version
```

## Configure Git Username

```bash
git config --global user.name "Your Name"
```

## Configure Git Email

```bash
git config --global user.email "your-email@example.com"
```

## Clone the GitHub Repository

```bash
git clone repository_URL
```

## Enter the Repository

```bash
cd CS513-Software-Systems
```

## Create a Directory

```bash
mkdir day_0
```

## Create or Edit README

```bash
nano day_0/README.md
```

## Check File Contents

```bash
cat day_0/README.md
```

## Check Git Status

```bash
git status
```

## Add Files to Staging Area

```bash
git add day_0
```

## Create a Commit

```bash
git commit -m "Add Day 0 Software System fundamentals notes"
```

## Push to GitHub

```bash
git push
```

---

# 10. Day 0 Summary

On Day 0, I learned:

* Basic Software Systems concepts
* Operating System and Kernel
* System Calls
* Terminal and Shell
* Program vs Process
* Basic Linux navigation commands
* Creating directories
* Viewing file contents
* Using Nano
* Checking the GCC compiler
* Git and GitHub basics
* Cloning a GitHub repository
* Git staging
* Git commits
* Pushing changes to GitHub

---

# Questions for Future Learning

* How does a system call work internally?
* What happens when a C program calls a system call?
* What is the difference between user space and kernel space?
* How are files managed internally by Linux?
* What is an inode?

These concepts will be explored while completing the hands-on exercises.

