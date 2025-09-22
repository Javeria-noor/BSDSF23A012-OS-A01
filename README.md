# BSDSF23A012-OS-A01
BSDSF23AXXX-OS-A01
📌 Operating Systems Programming Assignment – 01

This project is a hands-on C programming assignment designed to teach modular programming, build automation, and professional Git/GitHub workflows. It evolves from simple multifile compilation to creating static & dynamic libraries, documentation via man pages, and GitHub releases.

🎯 Learning Objectives

Through this assignment, you will learn:

Modular Programming with .c and .h files

Creating Static (.a) and Dynamic (.so) libraries

Understanding the compilation & linking process (-I, -L, -l)

Automating builds with Makefile

Writing Linux man pages for documentation

Using binary analysis tools: nm, ar, readelf, ldd

Applying Git workflows: branching, merging, tagging

Publishing GitHub releases with assets

📂 Project Structure
ROLL_NO-OS-A01/
├── src/          # Source code (.c files)
├── include/      # Header files (.h files)
├── lib/          # Static and dynamic libraries (.a / .so)
├── bin/          # Final executables
├── obj/          # Compiled object files
├── man/          # Man pages (groff formatted)
└── REPORT.md     # Detailed report and answers

🚀 Features
🔹 Feature 1: Project Scaffolding & Version Control (5 Marks)

Set up repo & directory structure.

Placed project under Git version control.

Initial commit pushed to GitHub.

🔹 Feature 2: Multi-file Build (20 Marks)

Compiled multiple .c files into one executable.

Wrote Makefile for direct compilation.

Created first release v0.1.1-multifile with bin/client.

🔹 Feature 3: Static Library (25 Marks)

Bundled functions into libmyutils.a.

Modified Makefile to link against static library.

Created release v0.2.1-static with bin/client_static + lib/libmyutils.a.

🔹 Feature 4: Dynamic Library (25 Marks)

Built libmyutils.so with -fPIC & --shared.

Linked bin/client_dynamic against it.

Used LD_LIBRARY_PATH to run dynamic client.

Created release v0.3.1-dynamic with bin/client_dynamic + lib/libmyutils.so.

🔹 Feature 5: Man Pages & Installation (15 Marks)

Created Linux man page for client utility.

Added install target in Makefile.

Tested with man mycat and make install.

Created final release v0.4.1-final.

⚙️ Build & Run Instructions
🛠 Build using Makefile
make            # Builds the default client
make static     # Builds static client using libmyutils.a
make dynamic    # Builds dynamic client using libmyutils.so

▶️ Run executables
./bin/client
./bin/client_static
./bin/client_dynamic

📝 Install & Test
sudo make install
client
man mycat

🛠 Tools Used

C Compiler (gcc)

Make Utility

ar, ranlib → for static libraries

ldd, nm, readelf → for binary inspection

groff → for man page formatting

Git & GitHub → version control & releases

🏷 Git Workflow & Releases

Each feature implemented in a separate branch.

Merged into main after completion.

Annotated tags created at stable points:

v0.1.1-multifile

v0.2.1-static

v0.3.1-dynamic

v0.4.1-final

GitHub releases published with appropriate assets.

👩‍💻 Author

Javeria Noor
📧 javerianoor013@gmail.com
