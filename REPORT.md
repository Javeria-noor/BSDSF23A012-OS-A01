# REPORT.md

## Feature 1: Project Scaffolding & Version Control  

### Task 1: GitHub Repository  
- A new GitHub repository was created with the required naming convention: **BSDSF23A012-OS-A01**.  
- The repository was initialized with a `README.md` file.  

### Task 2: Cloning Repository  
- The repository was successfully cloned to the local Kali Linux system using `git clone`.  

### Task 3: Project Structure  
The following directory structure was created inside the repository:  

 
BSDSF23A012-OS-A01/
├── src/
├── include/
├── lib/
├── bin/
├── obj/
└── REPORT.md


### Task 4: Save and Push  
- All directories and the `REPORT.md` file were added to version control.  
- An initial commit was made with the message: *"Part 1: Added project scaffolding and REPORT.md"*.  
- The commit was successfully pushed to the `main` branch on GitHub.  

---

## Feature 2: Multi-File Build with String and File Functions  

### Task 1: Branch Creation  
- A new branch named **multifile-build** was created to implement Feature-2 without affecting the `main` branch.  

### Task 2: Multi-File Structure  
The project was organized into multiple files for modularity:  

- **Header files (.h):**  
  - `mystrfunctions.h` – declares string-related functions (`mystrlen`, `mystrcpy`, `mystrncpy`, `mystrcat`).  
  - `myfilefunctions.h` – declares file-related functions (`wordCount`, `mygrep`).  

- **Source files (.c):**  
  - `mystrfunctions.c` – implements all string functions.  
  - `myfilefunctions.c` – implements all file functions.  
  - `main.c` – tests string and file functions.  

- **Makefile:** automates compilation of all `.c` files into a single executable.  

### Task 3: Implementation and Testing  
- String functions were tested with sample strings.  
- File functions were tested on `test.txt` to count lines, words, and characters.  
- The program compiled and ran successfully, producing correct results.  

### Task 4: Version Control  
- All files were added, committed, and pushed to the `multifile-build` branch on GitHub.  
- A tag **v0.1.1-multifile** was created to mark this stable version.  

### Report Questions  
1. **Explain the linking rule in this Makefile: `$(TARGET): $(OBJECTS)`**  
   - The final executable (`$(TARGET)`) depends on all object files (`$(OBJECTS)`).  
   - The linker combines all `.o` files into a single program.  
   - Difference from library linking: instead of linking each `.o` file individually, we link against a precompiled `.a` or `.so` library.  

2. **What is a git tag and why is it useful? Difference between simple and annotated tags?**  
   - Git tags mark important commits, such as releases.  
   - **Lightweight tag:** a simple pointer to a commit.  
   - **Annotated tag:** contains metadata like author, date, and message — preferred for official releases.  

3. **Purpose of a "Release" on GitHub and attaching binaries:**  
   - Releases package software for users.  
   - Attaching binaries (e.g., `bin/client`) allows users to run the program without compiling.  

---

## Feature 3: Static Library Build  

### Overview  
- Utility functions were compiled into a static library: `lib/libmyutils.a` using `ar` and `ranlib`.  
- The Makefile was modified to build and link against this static library.  
- The final executable `bin/client_static` was successfully built and tested.  

### Report Questions  
1. **Compare Makefile from Part 2 and Part 3:**  
   - Part 2: links directly with `.o` object files.  
   - Part 3: archives `.o` files into a static library `.a`, linking `main.c` against the library.  

2. **Purpose of `ar` and `ranlib`:**  
   - `ar`: creates an archive of object files (`.a` static library).  
   - `ranlib`: generates an index inside the library for faster linking.  

3. **When running `nm` on `client_static`:**  
   - Symbols like `mystrlen` are inside the executable.  
   - This shows static linking copies the function code into the binary.  

---

## Feature 4: Dynamic Library Build  

### Overview  
- Project converted to a **dynamic/shared library** (`.so`).  
- All utility functions were compiled with `-fPIC` (position-independent code) and linked using `-shared` to generate `lib/libmyutils.so`.  
- The executable `bin/client_dynamic` was linked dynamically.  

### Report Questions  
1. **Difference between static and dynamic linking:**  
   - Static: code copied into the executable → larger binary.  
   - Dynamic: references the `.so` library → smaller executable; library loaded at runtime.  

2. **Role of `LD_LIBRARY_PATH`:**  
   - Specifies directories where the system searches for shared libraries at runtime.  

3. **What does `ldd bin/client_dynamic` show?**  
   - Lists dynamic dependencies, confirming linkage against `libmyutils.so`.  

---

## Feature 5: Man Pages & Installation  

### Overview  
- Created a **manual page**: `man/mycat.3`.  
- Makefile updated with `install` and `uninstall` targets:  
  - `make install`: copies executable to `/usr/local/bin` and man page to `/usr/local/share/man`.  
  - `make uninstall`: removes them.  

### Report Questions  
1. **Structure of a man page:**  
   - Sections include NAME, SYNOPSIS, DESCRIPTION, OPTIONS, EXAMPLES, AUTHOR, etc.  

2. **Why include an install target in Makefile?**  
   - Professionalizes the project.  
   - Users can install/uninstall like real Linux packages.  

---

## Feature 6: Final Submission & Documentation  

### Overview  
- Finalized `REPORT.md` documenting all features.  
- Merged the `documentation` branch back into `main`.  
- Pushed all branches and tags to GitHub:  
  - `multifile-build`  
  - `static-build`  
  - `dynamic-build`  
  - `man-pages`  
  - `documentation`  

### Report Questions  
1. **Why keep feature branches instead of working directly on main?**  
   - Keeps workflow clean and avoids breaking main.  
   - Each feature is isolated and can be tested independently.  

2. **Why push all branches for grading?**  
   - Shows full development history.  
   - Instructor can verify incremental progress and versioning.  

---

# ✅ Final Note  
This project demonstrated:  
- Project scaffolding and Git basics.  
- Multi-file compilation and Makefiles.  
- Creating and using static and dynamic libraries.  
- Writing man pages and adding installation targets.  
- Proper use of Git branching, tagging, and GitHub releases.
 
