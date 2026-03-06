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

## 2. Resources

**Learning Materials:**

- [Unix Shell - Wikipedia](https://en.wikipedia.org/wiki/Unix_shell)
- [Thompson Shell History](https://en.wikipedia.org/wiki/Thompson_shell)
- [Ken Thompson Biography](https://en.wikipedia.org/wiki/Ken_Thompson)
- [Fork System Call - man page](https://man7.org/linux/man-pages/man2/fork.2.html)
- [Execve System Call - man page](https://man7.org/linux/man-pages/man2/execve.2.html)
- [Wait/Waitpid - man page](https://man7.org/linux/man-pages/man2/wait.2.html)

**Development Tools:**

- [Betty Style Guide](https://github.com/alx-tools/Betty)
- [GCC Compiler Documentation](https://gcc.gnu.org/onlinedocs/)
- [Valgrind Memory Debugger](https://valgrind.org/docs/manual/manual.html)

**Reference Documentation:**

- [GNU C Library Manual](https://www.gnu.org/software/libc/manual/)
- [POSIX Standards](https://pubs.opengroup.org/onlinepubs/9699919799/)
- [Advanced Programming in the UNIX Environment by W. Richard Stevens](https://www.apuebook.com/)

---