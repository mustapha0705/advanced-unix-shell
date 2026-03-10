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