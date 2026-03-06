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
- Maintain clean, readable code following Betty coding style standards
- Handle edge cases and errors gracefully with appropriate error messages
- Demonstrate proficiency in C programming and systems programming concepts

**Key Tech Stack:**

C Programming Language (C89 Standard), GCC Compiler, Linux System Calls (fork, execve, wait, chdir, stat), Standard C Library, POSIX APIs

---