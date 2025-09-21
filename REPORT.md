# REPORT.md

## Feature 1: Project Scaffolding & Version Control

### Task 1: GitHub Repository
- A new GitHub repository was created with the required naming convention: **BSDSF23A012-OS-A01**.
- The repository was initialized with a README.md file.

### Task 2: Cloning Repository
- The repository was successfully cloned into the local Kali Linux system using git.

### Task 3: Project Structure
- The following directory structure was created inside the repository:
ROLL_NO-OS-A01/
├── src/
├── include/
├── lib/
├── bin/
├── obj/
└── REPORT.md

### Task 4: Save and Push
- All directories and the REPORT.md file were added to version control.
- An initial commit was made with the message: *"Part 1: Added project scaffolding and REPORT.md"*.
- The commit was successfully pushed to the main branch on GitHub.

## Feature 2: Multi-File Build with String and File Functions

### Task 1: Branch Creation
- A new branch named `multifile-build` was created to implement Feature-2 without affecting the main branch.

### Task 2: Multi-File Structure
- The project was organized into multiple files for better modularity:
  - **Header files (`.h`)**:
    - `mystrfunctions.h` – declares string-related functions (`strlen`, `strcpy`, `strncpy`, `strcat`).
    - `myfilefunctions.h` – declares file-related functions (`wordCount`, `mygrep`).
  - **Source files (`.c`)**:
    - `mystrfunctions.c` – implements all string functions.
    - `myfilefunctions.c` – implements all file functions.
    - `main.c` – tests the string and file functions.
  - **Test file (`test.txt`)** – used for testing file functions.
  - **Makefile** – automates compilation of all `.c` files into a single executable program.

### Task 3: Implementation and Testing
- String functions were tested with sample strings.  
- File functions were tested on `test.txt` to count lines, words, and characters.  
- The program compiled and ran successfully, producing correct results.

### Task 4: Version Control
- All files were added, committed, and pushed to the `multifile-build` branch on GitHub.  
- A tag `v0.1.1-multifile` was created to mark this stable version.



# Feature 4: Dynamic Library Build

## 1. Overview

In this feature, the project was evolved to use a **dynamic/shared library** (`.so`) instead of static linking. This approach allows the operating system to load the library into memory at runtime, reducing executable size and enabling efficient memory usage.

---

## 2. Implementation Details

### a) Position-Independent Code (-fPIC)

- All library source files (`myfilefunctions.c`, `mystrfunctions.c`) were compiled with the `-fPIC` flag:
  
```bash
gcc -fPIC -c src/myfilefunctions.c -o obj/myfilefunctions.o
gcc -fPIC -c src/mystrfunctions.c -o obj/mystrfunctions.o

## Feature 5: Creating and Accessing Man Pages

**Concepts Covered:** Linux Documentation, man pages, groff formatting, Makefile install Target

---

### Task 1: Branch Setup
- Created a new branch `man-pages` from the updated `main` branch.
- All changes related to documentation and install target were committed to this branch.

---

### Task 2: Man Page Creation
- Created the directories:

```bash
mkdir -p man/man3
