# Advanced Custom Unix Shell

---

## 1. Project Overview

**Brief Description:**

Advanced Shell is a custom-built UNIX command line interpreter developed in C, designed to replicate the core functionality of the standard `/bin/sh` shell. The project addresses the challenge of understanding low-level operating system interactions by implementing a fully functional shell from scratch. It handles user input processing, command execution via fork-exec model, and PATH resolution for executable lookup. Additionally, it provides comprehensive error handling and memory management—all while adhering to strict coding standards and best practices.

**Project Goals:**

- Develop a fully functional UNIX command interpreter that mimics `/bin/sh` behavior
- Implement robust process management using fork(), execve(), and wait() system calls
- Provide support for both interactive and non-interactive command execution modes
- Implement essential built-in commands (exit, env, cd, setenv, unsetenv)
- Ensure proper memory management with zero memory leaks
- Maintain clean, readable code
- Handle edge cases and errors gracefully with appropriate error messages
- Demonstrate proficiency in C programming and systems programming concepts

**Key Tech Stack:**

C Programming Language (C89 Standard), GCC Compiler, Linux System Calls (fork, execve, wait, chdir, stat), Standard C Library, POSIX APIs

---

## 2. Feature Breakdown

**Core Shell Functionality:**

- **Interactive Mode**: Displays a prompt (`$ `), reads user input, executes commands, and displays the prompt again after each command completion. Provides a user-friendly command-line interface similar to standard shells.

- **Non-Interactive Mode**: Accepts commands from pipes or files without displaying prompts. Enables automation and script execution by processing commands line-by-line from stdin.

- **Command Execution with Arguments**: Parses command lines into command name and multiple arguments, then executes the specified program with the provided arguments using the execve system call.

- **PATH Resolution**: Automatically searches directories listed in the PATH environment variable to locate executable files. Users can run commands by name (e.g., `ls`) without specifying the full path (`/bin/ls`).

- **Built-in Command: exit**: Terminates the shell with an optional exit status code. Supports `exit` (uses last command status) and `exit n` (exits with status n). Validates numeric arguments and reports errors for illegal values.

- **Built-in Command: env**: Prints all environment variables in the format `KEY=VALUE`, one per line. Provides visibility into the current process environment without external dependencies.

- **Built-in Command: cd**: Changes the current working directory. Supports `cd` (goes to HOME), `cd <directory>` (changes to specified path), and `cd -` (switches to previous directory). Updates PWD and OLDPWD environment variables automatically.

- **Built-in Command: setenv**: Creates a new environment variable or modifies an existing one. Usage: `setenv VARIABLE VALUE`. Validates input to ensure both variable name and value are provided.

- **Built-in Command: unsetenv**: Removes an environment variable from the environment. Usage: `unsetenv VARIABLE`. Validates that the variable name is provided and handles non-existent variables gracefully.

- **Error Handling**: Provides informative error messages when commands are not found, execution fails, or invalid arguments are provided. Error messages include the shell name and command line number for debugging.

- **EOF Handling (Ctrl+D)**: Gracefully handles end-of-file condition by exiting the shell cleanly when EOF is detected on stdin. Ensures proper resource cleanup and status code return.

- **Memory Management**: Implements thorough memory cleanup with no memory leaks. All dynamically allocated memory is properly freed before program termination. Validated with Valgrind memory checker.

- **Signal Handling**: Responds appropriately to Ctrl+C (SIGINT) by displaying a new prompt without terminating the shell, maintaining user session continuity.

- **Custom String Functions**: Implements custom versions of standard string functions (_strlen, _strcmp, _strcpy, _strcat, _strdup) to minimize dependencies and demonstrate low-level string manipulation.

---

## 3. Resources

**Learning Materials:**

- [Unix Shell - Wikipedia](https://en.wikipedia.org/wiki/Unix_shell)
- [Thompson Shell History](https://en.wikipedia.org/wiki/Thompson_shell)
- [Ken Thompson Biography](https://en.wikipedia.org/wiki/Ken_Thompson)
- [Fork System Call - man page](https://man7.org/linux/man-pages/man2/fork.2.html)
- [Execve System Call - man page](https://man7.org/linux/man-pages/man2/execve.2.html)
- [Wait/Waitpid - man page](https://man7.org/linux/man-pages/man2/wait.2.html)

**Development Tools:**

- [GCC Compiler Documentation](https://gcc.gnu.org/onlinedocs/)
- [Valgrind Memory Debugger](https://valgrind.org/docs/manual/manual.html)

**Reference Documentation:**

- [GNU C Library Manual](https://www.gnu.org/software/libc/manual/)
- [POSIX Standards](https://pubs.opengroup.org/onlinepubs/9699919799/)
- [Advanced Programming in the UNIX Environment by W. Richard Stevens](https://www.apuebook.com/)

---

## 4. Created By

**Mustapha Mohammed** ([@Mustapha0705](https://github.com/mustapha0705))

Systems Programmer | C/C++ Enthusiast | Low Level Programmer | Backend Engineer

Email: mustapha.mohammedu12@gmail.com