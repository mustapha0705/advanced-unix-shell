#include "shell.h"

/**
 * is_builtin - Checks if a command is a built-in shell command.
 * @command: The command to check.
 *
 * Return: 1 if the command is a built-in, 0 otherwise.
 */
int is_builtin(char *command)
{
    char *builtins[] =
        {
            "exit", "env", "setenv", "unsetenv",
            "cd", NULL};
    int i;

    for (i = 0; builtins[i]; i++)
    {
        if (strcmp(command, builtins[i]) == 0)
            return (1);
    }
    return (0);
}

/**
 * handle_builtin - Executes a built-in shell command.
 * @command: The built-in command and its arguments.
 * @argv: The command line arguments.
 * @status: The exit status of the last command.
 * @idx: The index of the command in the input.
 */
void handle_builtin(char **command, char **argv, int *status, int idx)
{
    if (strcmp(command[0], "exit") == 0)
        exit_shell(command, argv, status, idx);
    else if (strcmp(command[0], "env") == 0)
        print_env(command, status);
    /*TODO:
     else if (strcmp(command[0], "setenv") == 0)
         handle_setenv(command, status);
     else if (strcmp(command[0], "unsetenv") == 0)
         handle_unsetenv(command, status); */
}

void exit_shell(char **command, char **argv, int *status, int idx)
{
    // handle shell exit
}

/**
 * print_env - Handles the 'env' built-in command.
 * @command: The env command and its arguments.
 * @status: The exit status of the last command.
 */
void print_env(char **command, int *status)
{
    int i;

    for (i = 0; environ[i]; i++)
    {
        write(STDOUT_FILENO, environ[i], strlen(environ[i]));
        write(STDOUT_FILENO, "\n", 1);
    }
    // free2Darray(command);
    (*status) = 0;
}